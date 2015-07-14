/*
 * Copyright (C) 2015 Atmel Corporation
 *
 *  Atmel Quad SPI Interface (QSPI) driver
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include <malloc.h>
#include <spi.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/clk.h>
#include "atmel_qspi.h"

#define OFFSET_BITS_MASK	0x00ffffff

#define	SPI_FLASH_3B_ADDR_LEN	3
#define	SPI_FLASH_CMD_LEN	1

#define	CMD_QUAD_OUTPUT_FAST_READ	0x6b
#define	CMD_QUAD_IO_FAST_READ		0xeb
#define	CMD_QUAD_INPUT_FAST_PROGRAM	0x32

static u32 reg_bases[] = {
	ATMEL_BASE_QSPI0,
	ATMEL_BASE_QSPI1,
};

static u32 mem_bases[] = {
	ATMEL_BASE_QSPI0_MEM,
	ATMEL_BASE_QSPI1_MEM,
};

struct atmel_qspi_slave {
	struct spi_slave slave;
	u32	reg_base;
	u32	mem_base;
};

static inline struct atmel_qspi_slave *to_atmel_qspi_slave(struct spi_slave *slave)
{
	return container_of(slave, struct atmel_qspi_slave, slave);
}

void spi_init(void)
{
}

struct spi_slave *spi_setup_slave(unsigned int bus, unsigned int cs,
				  unsigned int max_hz, unsigned int mode)
{
	struct atmel_qspi_slave *qspi;
	struct atmel_qspi_regs *regs;
	u32 scbr;
	u32 reg;

	if (bus >= ARRAY_SIZE(reg_bases))
		return NULL;

	qspi = spi_alloc_slave(struct atmel_qspi_slave, bus, cs);
	if (!qspi)
		return NULL;

	qspi->reg_base = reg_bases[bus];
	qspi->mem_base = mem_bases[bus];
	regs = (struct atmel_qspi_regs *)qspi->reg_base;

	writel(ATMEL_QSPI_CR_QSPIDIS, &regs->cr);
	writel(ATMEL_QSPI_CR_SWRST, &regs->cr);

	scbr = (get_spi_clk_rate(bus) + max_hz - 1) / max_hz;
	if (scbr > ATMEL_QSPI_SCR_SCBR_MAX)
		return NULL;

	if (scbr < 1)
		scbr = 1;

	reg = ATMEL_QSPI_SCR_SCBR_(scbr);
	if (mode == SPI_MODE_1)
		reg |= ATMEL_QSPI_SCR_CPHA;
	else if (mode == SPI_MODE_2)
		reg |= ATMEL_QSPI_SCR_CPOL;
	else if (mode == SPI_MODE_3)
		reg |= ATMEL_QSPI_SCR_CPHA | ATMEL_QSPI_SCR_CPOL;

	writel(reg, &regs->scr);

	reg = ATMEL_QSPI_MR_SMM_MEMORY;
	writel(reg, &regs->mr);

	return &qspi->slave;
}

void spi_free_slave(struct spi_slave *slave)
{
	struct atmel_qspi_slave *qspi = to_atmel_qspi_slave(slave);

	free(qspi);
}

int spi_claim_bus(struct spi_slave *slave)
{
	struct atmel_qspi_slave *qspi = to_atmel_qspi_slave(slave);
	struct atmel_qspi_regs *regs = (struct atmel_qspi_regs *)qspi->reg_base;

	writel(ATMEL_QSPI_CR_QSPIEN, &regs->cr);

	return 0;
}

void spi_release_bus(struct spi_slave *slave)
{
	struct atmel_qspi_slave *qspi = to_atmel_qspi_slave(slave);
	struct atmel_qspi_regs *regs = (struct atmel_qspi_regs *)qspi->reg_base;

	writel(ATMEL_QSPI_CR_QSPIDIS, &regs->cr);
}

int qspi_send_command(struct spi_slave *slave,
		      const u8 *cmd, size_t cmd_len,
		      const u8 *data_out, u8 *data_in, size_t data_len)
{
	struct atmel_qspi_slave *qspi = to_atmel_qspi_slave(slave);
	struct atmel_qspi_regs *regs = (struct atmel_qspi_regs *)qspi->reg_base;
	u32 cmdbuf, membuf;
	u32 dummy_cycles = 0, sf_offset = 0;
	bool has_address = false;
	u32 frame = 0;
	u8 command = *cmd;

	if ((command == CMD_QUAD_OUTPUT_FAST_READ) ||
	    (command == CMD_QUAD_IO_FAST_READ) ||
	    (command == CMD_QUAD_INPUT_FAST_PROGRAM))
		frame |= ATMEL_QSPI_IFR_WIDTH_QUAD_CMD;
	else
		frame |= ATMEL_QSPI_IFR_WIDTH_SINGLE_BIT_SPI;

	frame |= ATMEL_QSPI_IFR_INSTEN;

	if (cmd_len > SPI_FLASH_CMD_LEN) {
		has_address = true;
		memcpy(&cmdbuf, cmd, SPI_FLASH_3B_ADDR_LEN + SPI_FLASH_CMD_LEN);
		sf_offset = swab32(cmdbuf) & OFFSET_BITS_MASK;
		dummy_cycles = cmd_len - SPI_FLASH_CMD_LEN - SPI_FLASH_3B_ADDR_LEN;
	}

	if (has_address)
		frame |= ATMEL_QSPI_IFR_ADDREN;

	if (data_in || data_out)
		frame |= ATMEL_QSPI_IFR_DATAEN;

	if (data_out) {
		if (has_address)
			frame |= ATMEL_QSPI_IFR_TFRTYPE_WRITE_MEMORY;
		else
			frame |= ATMEL_QSPI_IFR_TFRTYPE_WRITE;
	}
	if (data_in) {
		if (has_address)
			frame |= ATMEL_QSPI_IFR_TFRTYPE_READ_MEMORY;
		else
			frame |= ATMEL_QSPI_IFR_TFRTYPE_READ;
	}

	frame |= ATMEL_QSPI_IFR_NBDUM_(dummy_cycles * 8);

	if ((!data_in && !data_out) && has_address)
		writel(sf_offset, &regs->iar);

	writel(command, &regs->icr);
	writel(frame, &regs->ifr);

	readl(&regs->ifr);	/* To synchronize system bus access */

	if (data_in || data_out) {
		membuf = qspi->mem_base + sf_offset;
		if (data_out)
			memcpy((u8 *)membuf, data_out, data_len);

		if (data_in)
			memcpy(data_in, (u8 *)membuf, data_len);
	}

	writel(ATMEL_QSPI_CR_LASTXFER, &regs->cr);

	while (!(readl(&regs->sr) & ATMEL_QSPI_SR_INSTRE))
		;

	return 0;
}
