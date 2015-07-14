/*
 * Copyright (C) 2015 Atmel Corporation
 *
 * Register definitions for Atmel QSPI
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef _ATMEL_QSPI_H_
#define	_ATMEL_QSPI_H_

struct atmel_qspi_regs {
	u32	cr;		/* 0x00 */
	u32	mr;		/* 0x04 */
	u32	rdr;		/* 0x08 */
	u32	tdr;		/* 0x0c */
	u32	sr;		/* 0x10 */
	u32	ier;		/* 0x14 */
	u32	idr;		/* 0x18 */
	u32	imr;		/* 0x1c */
	u32	scr;		/* 0x20 */
	u32	reserved0[3];	/* 0x24 ~ 0x2c */
	u32	iar;		/* 0x30 */
	u32	icr;		/* 0x34 */
	u32	ifr;		/* 0x38 */
	u32	reserved1;	/* 0x3c */
	u32	smr;		/* 0x40 */
	u32	skr;		/* 0x44 */
	u32	reserved2[39];	/* 0x48 ~ 0xe0 */
	u32	wpmr;		/* 0xe4 */
	u32	wpsr;		/* 0xe8 */
};

/* QSPI_CR */
#define	ATMEL_QSPI_CR_QSPIEN		(0x1 << 0)
#define	ATMEL_QSPI_CR_QSPIDIS		(0x1 << 1)
#define	ATMEL_QSPI_CR_SWRST		(0x1 << 7)
#define	ATMEL_QSPI_CR_LASTXFER		(0x1 << 24)

/* QSPI_MR */
#define	ATMEL_QSPI_MR_SMM		(0x1 << 0)
#define		ATMEL_QSPI_MR_SMM_SPI		(0x0 << 0)
#define		ATMEL_QSPI_MR_SMM_MEMORY	(0x1 << 0)
#define	ATMEL_QSPI_MR_LLB		(0x1 << 1)
#define		ATMEL_QSPI_MR_LLB_DISABLED	(0x0 << 1)
#define		ATMEL_QSPI_MR_LLB_ENABLED	(0x1 << 1)
#define	ATMEL_QSPI_MR_WDRBT		(0x1 << 2)
#define		ATMEL_QSPI_MR_WDRBT_DISABLED	(0x0 << 2)
#define		ATMEL_QSPI_MR_WDRBT_ENABLED	(0x1 << 2)
#define	ATMEL_QSPI_MR_SMRM		(0x1 << 3)
#define		ATMEL_QSPI_MR_SMRM_AHB		(0x0 << 3)
#define		ATMEL_QSPI_MR_SMRM_APB		(0x1 << 3)
#define	ATMEL_QSPI_MR_CSMODE		(0x3 << 4)
#define		ATMEL_QSPI_MR_CSMODE_NOT_RELOADED	(0x0 << 4)
#define		ATMEL_QSPI_MR_CSMODE_LASTXFER		(0x1 << 4)
#define		ATMEL_QSPI_MR_CSMODE_SYSTEMATICALLY	(0x2 << 4)
#define	ATMEL_QSPI_MR_NBBITS			(0xf << 8)
#define		ATMEL_QSPI_MR_NBBITS_8_BIT	(0x0 << 8)
#define		ATMEL_QSPI_MR_NBBITS_16_BIT	(0x8 << 8)
#define	ATMEL_QSPI_MR_DLYBCT		(0xff << 16)
#define	ATMEL_QSPI_MR_DLYCS		(0xff << 24)

/* QSPI_SR */
#define	ATMEL_QSPI_SR_RDRF		(0x1 << 0)
#define	ATMEL_QSPI_SR_TDRE		(0x1 << 1)
#define	ATMEL_QSPI_SR_TXEMPTY		(0x1 << 2)
#define	ATMEL_QSPI_SR_OVRES		(0x1 << 3)
#define	ATMEL_QSPI_SR_CSR		(0x1 << 8)
#define	ATMEL_QSPI_SR_CSS		(0x1 << 9)
#define	ATMEL_QSPI_SR_INSTRE		(0x1 << 10)
#define	ATMEL_QSPI_SR_QSPIENS		(0x1 << 24)

/* QSPI_SCR */
#define	ATMEL_QSPI_SCR_CPOL		(0x1 << 0)
#define	ATMEL_QSPI_SCR_CPHA		(0x1 << 1)
#define	ATMEL_QSPI_SCR_SCBR_MAX		0xff
#define	ATMEL_QSPI_SCR_SCBR_(x)		((x) << 8)
#define	ATMEL_QSPI_SCR_DLYBS_(x)	((x) << 16)

/* QSPI_ICR */
#define	ATMEL_QSPI_ICR_INST_(x)		((x) << 0)
#define	ATMEL_QSPI_ICR_OPT_(x)		((x) << 16)

/* QSPI_IFR */
#define	ATMEL_QSPI_IFR_WIDTH		(0x7 << 0)
#define		ATMEL_QSPI_IFR_WIDTH_SINGLE_BIT_SPI	(0x0 << 0)
#define		ATMEL_QSPI_IFR_WIDTH_DUAL_OUTPUT	(0x1 << 0)
#define		ATMEL_QSPI_IFR_WIDTH_QUAD_OUTPUT	(0x2 << 0)
#define		ATMEL_QSPI_IFR_WIDTH_DUAL_IO		(0x3 << 0)
#define		ATMEL_QSPI_IFR_WIDTH_QUAD_IO		(0x4 << 0)
#define		ATMEL_QSPI_IFR_WIDTH_DUAL_CMD		(0x5 << 0)
#define		ATMEL_QSPI_IFR_WIDTH_QUAD_CMD		(0x6 << 0)
#define	ATMEL_QSPI_IFR_INSTEN		(0x1 << 4)
#define	ATMEL_QSPI_IFR_ADDREN		(0x1 << 5)
#define	ATMEL_QSPI_IFR_OPTEN		(0x1 << 6)
#define	ATMEL_QSPI_IFR_DATAEN		(0x1 << 7)
#define	ATMEL_QSPI_IFR_OPTL		(0x3 << 8)
#define		ATMEL_QSPI_IFR_OPTL_1BIT		(0x0 << 8)
#define		ATMEL_QSPI_IFR_OPTL_2BIT		(0x1 << 8)
#define		ATMEL_QSPI_IFR_OPTL_4BIT		(0x2 << 8)
#define		ATMEL_QSPI_IFR_OPTL_8BIT		(0x3 << 8)
#define	ATMEL_QSPI_IFR_ADDRL		(0x1 << 10)
#define		ATMEL_QSPI_IFR_ADDRL_24_BIT		(0x0 << 10)
#define		ATMEL_QSPI_IFR_ADDRL_32_BIT		(0x1 << 10)
#define	ATMEL_QSPI_IFR_TFRTYPE		(0x3 << 12)
#define		ATMEL_QSPI_IFR_TFRTYPE_READ		(0x0 << 12)
#define		ATMEL_QSPI_IFR_TFRTYPE_READ_MEMORY	(0x1 << 12)
#define		ATMEL_QSPI_IFR_TFRTYPE_WRITE		(0x2 << 12)
#define		ATMEL_QSPI_IFR_TFRTYPE_WRITE_MEMORY	(0x3 << 12)
#define	ATMEL_QSPI_IFR_CRM		(0x1 << 14)
#define	ATMEL_QSPI_IFR_NBDUM_(x)	((x) << 16)

#endif /* #ifndef _ATMEL_QSPI_H_ */
