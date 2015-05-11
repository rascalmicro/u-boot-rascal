/*
 * Copyright (C) 2015
 * Wenyou Yang, wenyou.yang@atmel.com
 *
 * Chip Identifier (CHIPID)
 * Based on SAMA5D2 datasheet
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef AT91_CHIPID_H
#define AT91_CHIPID_H

#ifndef __ASSEMBLY__
typedef struct at91_chipid {
	u32	chipid_cidr;	/* Chip ID Register */
	u32	chipid_exid;	/* Chip ID Extension Register */
} at91_chipid_t;

#endif /* __ASSEMBLY__ */

#define	AT91_CHIPID_VERSION	(0x1f << 0)
#define	AT91_CHIPID_EPROC	(0x07 << 5)
#define		AT91_CHIPID_EPROC_ARM946ES	(0x1 << 5)
#define		AT91_CHIPID_EPROC_ARM7TDMI	(0x2 << 5)
#define		AT91_CHIPID_EPROC_CM3		(0x3 << 5)
#define		AT91_CHIPID_EPROC_ARM920T	(0x4 << 5)
#define		AT91_CHIPID_EPROC_ARM926EJS	(0x5 << 5)
#define		AT91_CHIPID_EPROC_CA5		(0x6 << 5)
#define		AT91_CHIPID_EPROC_CM4		(0x7 << 5)
#define	AT91_CHIPID_NVPSIZ	(0x0f << 8)
#define	AT91_CHIPID_NVPSIZ2	(0x0f << 12)
#define	AT91_CHIPID_SRAMSIZ	(0x0f << 16)
#define	AT91_CHIPID_ARCH	(0xff << 20)
#define	AT91_CHIPID_NVPTYP	(0x07 << 28)
#define	AT91_CHIPID_EXT		(0x01 << 31)

#endif
