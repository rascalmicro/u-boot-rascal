/*
 * Copyright (C) 2015 Atmel Corporation
 *		      Wenyou Yang <wenyou.yang@atmel.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/at91_pmc.h>

void at91_periph_clk_enable(int id)
{
	struct at91_pmc *pmc = (struct at91_pmc *)ATMEL_BASE_PMC;

#ifdef CPU_HAS_PCR
	u32 regval;
	u32 div_value;

	if (id > AT91_PMC_PCR_PID_MASK)
		return;

	writel(id, &pmc->pcr);

	div_value = readl(&pmc->pcr) & AT91_PMC_PCR_DIV;

	regval = AT91_PMC_PCR_EN | AT91_PMC_PCR_CMD_WRITE | id | div_value;

	writel(regval, &pmc->pcr);
#else
	u32 mask = 0x01 << (id % 32);
	void *addr = (id / 32)  ?  &pmc->pcer1 : &pmc->pcer;

	writel(mask, addr);
#endif
}

void at91_periph_clk_disable(int id)
{
	struct at91_pmc *pmc = (struct at91_pmc *)ATMEL_BASE_PMC;

#ifdef CPU_HAS_PCR
	u32 regval;

	if (id > AT91_PMC_PCR_PID_MASK)
		return;

	regval = AT91_PMC_PCR_CMD_WRITE | id;

	writel(regval, &pmc->pcr);
#else
	u32 mask = 0x01 << (id % 32);
	void *addr = (id / 32)  ?  &pmc->pcdr1 : &pmc->pcdr;

	writel(mask, addr);
#endif
}

void at91_system_clk_enable(int sys_clk)
{
	struct at91_pmc *pmc = (struct at91_pmc *)ATMEL_BASE_PMC;

	writel((0x1 << sys_clk), &pmc->scer);
}

void at91_system_clk_disable(int sys_clk)
{
	struct at91_pmc *pmc = (struct at91_pmc *)ATMEL_BASE_PMC;

	writel((0x1 << sys_clk), &pmc->scdr);
}
