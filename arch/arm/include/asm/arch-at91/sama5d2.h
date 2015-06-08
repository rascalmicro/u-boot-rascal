/*
 * Chip-specific header file for the SAMA5D2 SoC
 *
 * Copyright (C) 2015 Atmel
 *		      Wenyou Yang <wenyou.yang@atmel.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __SAMA5D2_H
#define __SAMA5D2_H

/*
 * defines to be used in other places
 */
#define CONFIG_AT91FAMILY	/* It's a member of AT91 */

/*
 * Peripheral identifiers/interrupts.
 */
#define ATMEL_ID_FIQ		0	/* FIQ Interrupt ID */
/* 1 */
#define ATMEL_ID_ARM		2	/* Performance Monitor Unit */
#define ATMEL_ID_PIT		3	/* Periodic Interval Timer Interrupt */
#define ATMEL_ID_WDT		4	/* Watchdog Timer Interrupt */
#define ATMEL_ID_GMAC		5	/* Ethernet MAC */
#define ATMEL_ID_XDMAC0		6	/* DMA Controller 0 */
#define ATMEL_ID_XDMAC1		7	/* DMA Controller 1 */
#define ATMEL_ID_ICM		8	/* Integrity Check Monitor */
#define ATMEL_ID_AES		9	/* Advanced Encryption Standard */
#define ATMEL_ID_AESB		10	/* AES bridge */
#define ATMEL_ID_TDES		11	/* Triple Data Encryption Standard */
#define ATMEL_ID_SHA		12	/* SHA Signature */
#define ATMEL_ID_MPDDRC		13	/* MPDDR Controller */
#define ATMEL_ID_MATRIX1	14	/* H32MX, 32-bit AHB Matrix */
#define ATMEL_ID_MATRIX0	15	/* H64MX, 64-bit AHB Matrix */
#define ATMEL_ID_SECUMOD	16	/* Secure Module */
#define ATMEL_ID_HSMC		17	/* Multi-bit ECC interrupt */
#define ATMEL_ID_PIOA		18	/* Parallel I/O Controller A */
#define ATMEL_ID_FLEXCOM0	19	/* FLEXCOM0 */
#define ATMEL_ID_FLEXCOM1	20	/* FLEXCOM1 */
#define ATMEL_ID_FLEXCOM2	21	/* FLEXCOM2 */
#define ATMEL_ID_FLEXCOM3	22	/* FLEXCOM3 */
#define ATMEL_ID_FLEXCOM4	23	/* FLEXCOM4 */
#define ATMEL_ID_UART0		24	/* UART0 */
#define ATMEL_ID_UART1		25	/* UART1 */
#define ATMEL_ID_UART2		26	/* UART2 */
#define ATMEL_ID_UART3		27	/* UART3 */
#define ATMEL_ID_UART4		28	/* UART4 */
#define ATMEL_ID_TWIHS0		29	/* Two-wire Interface 0 */
#define ATMEL_ID_TWIHS1		30	/* Two-wire Interface 1 */
#define ATMEL_ID_SDHCI0		31	/* Secure Data Memory Card Controller 0 */
#define ATMEL_ID_SDHCI1		32	/* Secure Data Memory Card Controller 1 */
#define ATMEL_ID_SPI0		33	/* Serial Peripheral Interface 0 */
#define ATMEL_ID_SPI1		34	/* Serial Peripheral Interface 1 */
#define ATMEL_ID_TC0		35	/* Timer Counter 0 (ch.0,1,2) */
#define ATMEL_ID_TC1		36	/* Timer Counter 1 (ch.3,4,5) */
/* 37 */
#define ATMEL_ID_PWM		38	/* Pulse Width Modulation Controller0 (ch. 0,1,2,3) */
/* 39 */
#define ATMEL_ID_ADC		40	/* Touch Screen ADC Controller */
#define ATMEL_ID_UHPHS		41	/* USB Host High Speed */
#define ATMEL_ID_UDPHS		42	/* USB Device High Speed */
#define ATMEL_ID_SSC0		43	/* Serial Synchronous Controller 0 */
#define ATMEL_ID_SSC1		44	/* Serial Synchronous Controller 1 */
#define ATMEL_ID_LCDC		45	/* LCD Controller */
#define ATMEL_ID_ISI		46	/* Image Sensor Interface */
#define ATMEL_ID_TRNG		47	/* True Random Number Generator */
#define ATMEL_ID_PDMIC		48	/* Pulse Density Modulation Interface Controller */
#define ATMEL_ID_IRQ		49	/* IRQ Interrupt ID */
#define ATMEL_ID_SFC		50	/* Fuse Controller */
#define ATMEL_ID_SECURAM	51	/* Secure RAM */
#define ATMEL_ID_QSPI0		52	/* QSPI0 */
#define ATMEL_ID_QSPI1		53	/* QSPI1 */
#define ATMEL_ID_I2SC0		54	/* Inter-IC Sound Controller 0 */
#define ATMEL_ID_I2SC1		55	/* Inter-IC Sound Controller 1 */
#define ATMEL_ID_CAN0_INT0	56	/* MCAN 0 Interrupt0 */
#define ATMEL_ID_CAN1_INT0	57	/* MCAN 1 Interrupt0 */
#define ATMEL_ID_PTC		58	/* Peripheral Touch Controller */
#define ATMEL_ID_CLASSD		59	/* Audio Class D Amplifier */
#define ATMEL_ID_SFR		60	/* Special Function Register */
#define ATMEL_ID_SAIC		61	/* Secured Advanced Interrupt Controller */
#define ATMEL_ID_AIC		62	/* Advanced Interrupt Controller */
#define ATMEL_ID_L2CC		63	/* L2 Cache Controller */
#define ATMEL_ID_CAN0_INT1	64	/* MCAN 0 Interrupt1 */
#define ATMEL_ID_CAN1_INT1	65	/* MCAN 1 Interrupt1 */
#define ATMEL_ID_GMAC_Q1	66	/* GMAC Queue 1 Interrupt */
#define ATMEL_ID_GMAC_Q2	67	/* GMAC Queue 2 Interrupt */
#define ATMEL_ID_PIOB		68	/* Parallel I/O Controller B */
#define ATMEL_ID_PIOC		69	/* Parallel I/O Controller C */
#define ATMEL_ID_PIOD		70	/* Parallel I/O Controller D */
#define ATMEL_ID_SDHCI0_TIMER	71	/* Secure Data Memory Card Controller 0 */
#define ATMEL_ID_SDHCI1_TIMER	72	/* Secure Data Memory Card Controller 1 */
/* 73 */
#define ATMEL_ID_SYS		74	/* System Controller Interrupt */
#define ATMEL_ID_ACC		75	/* Analog Comparator */
#define ATMEL_ID_RXLP		76	/* UART Low-Power */
#define ATMEL_ID_SFRBU		77	/* Special Function Register BackUp */
#define ATMEL_ID_CHIPID		78	/* Chip ID */

/*
 * User Peripherals physical base addresses.
 */
#define	ATMEL_BASE_LCDC		0xf0000000
#define	ATMEL_BASE_XDMAC1	0xf0004000
#define	ATMEL_BASE_HXISI	0xf0008000
#define	ATMEL_BASE_MPDDRC	0xf000c000
#define	ATMEL_BASE_XDMAC0	0xf0010000
#define	ATMEL_BASE_PMC		0xf0014000
#define	ATMEL_BASE_MATRIX64	0xf0018000	/* MATRIX0 */
#define	ATMEL_BASE_AESB		0xf001c000
#define	ATMEL_BASE_QSPI0	0xf0020000
#define	ATMEL_BASE_QSPI1	0xf0024000
#define	ATMEL_BASE_SHA		0xf0028000
#define	ATMEL_BASE_AES		0xf002c000

#define	ATMEL_BASE_SPI0		0xf8000000
#define	ATMEL_BASE_SSC0		0xf8004000
#define	ATMEL_BASE_GMAC		0xf8008000
#define	ATMEL_BASE_TC0		0xf800c000
#define	ATMEL_BASE_TC1		0xf8010000
#define	ATMEL_BASE_HSMC		0xf8014000
#define	ATMEL_BASE_PDMIC	0xf8018000
#define	ATMEL_BASE_UART0	0xf801c000
#define	ATMEL_BASE_UART1	0xf8020000
#define	ATMEL_BASE_UART2	0xf8024000
#define	ATMEL_BASE_TWI0		0xf8028000
#define	ATMEL_BASE_PWMC		0xf802c000
#define	ATMEL_BASE_SFR		0xf8030000
#define	ATMEL_BASE_FLEXCOM0	0xf8034000
#define	ATMEL_BASE_FLEXCOM1	0xf8038000
#define	ATMEL_BASE_SAIC		0xf803c000
#define	ATMEL_BASE_ICM		0xf8040000
#define	ATMEL_BASE_SYSC		0xf8048000
#define	ATMEL_BASE_ACC		0xf804a000
#define	ATMEL_BASE_SFC		0xf804c000
#define	ATMEL_BASE_I2SC0	0xf8050000
#define	ATMEL_BASE_CAN0		0xf8054000

#define	ATMEL_BASE_SPI1		0xfc000000
#define	ATMEL_BASE_SSC1		0xfc004000
#define	ATMEL_BASE_UART3	0xfc008000
#define	ATMEL_BASE_UART4	0xfc00c000
#define	ATMEL_BASE_FLEXCOM2	0xfc010000
#define	ATMEL_BASE_FLEXCOM3	0xfc014000
#define	ATMEL_BASE_FLEXCOM4	0xfc018000
#define	ATMEL_BASE_TRNG		0xfc01c000
#define	ATMEL_BASE_AIC		0xfc020000
#define	ATMEL_BASE_TWI1		0xfc028000
#define	ATMEL_BASE_UDPHS	0xfc02c000
#define	ATMEL_BASE_ADC		0xfc030000

#define	ATMEL_BASE_PIOA		0xfc038000
#define	ATMEL_BASE_MATRIX32	0xfc03c000	/* MATRIX1 */
#define	ATMEL_BASE_SECUMOD	0xfc040000
#define	ATMEL_BASE_TDES		0xfc044000
#define	ATMEL_BASE_CLASSD	0xfc048000
#define	ATMEL_BASE_I2SC1	0xfc04c000
#define	ATMEL_BASE_CAN1		0xfc050000
#define	ATMEL_BASE_CHIPID	0xfc069000

/*
 * Address Memory Space
 */
#define	ATMEL_BASE_INTERNAL_MEM		0x00000000
#define	ATMEL_BASE_CS0			0x10000000
#define	ATMEL_BASE_DDRCS		0x20000000
#define	ATMEL_BASE_DDRCS_AES		0x40000000
#define	ATMEL_BASE_CS1			0x60000000
#define	ATMEL_BASE_CS2			0x70000000
#define	ATMEL_BASE_CS3			0x80000000
#define	ATMEL_BASE_QSPI0_AES_MEM	0x90000000
#define	ATMEL_BASE_QSPI1_AES_MEM	0x98000000
#define	ATMEL_BASE_SDHCI0		0xa0000000
#define	ATMEL_BASE_SDHCI1		0xb0000000
#define	ATMEL_BASE_NFC_CMD_REG		0xc0000000
#define	ATMEL_BASE_QSPI0_MEM		0xd0000000
#define	ATMEL_BASE_QSPI1_MEM		0xd8000000
#define	ATMEL_BASE_PERIPH		0xf0000000

/*
 * Internal Memories
 */
#define	ATMEL_BASE_ROM		0x00000000	/* ROM */
#define	ATMEL_BASE_ECC_ROM	0x00060000	/* ECC ROM */
#define	ATMEL_BASE_NFC_SRAM	0x00100000	/* NFC SRAM */
#define	ATMEL_BASE_SRAM0	0x00200000	/* SRAM0 */
#define	ATMEL_BASE_SRAM1	0x00220000	/* SRAM1 */
#define	ATMEL_BASE_UDPHS_FIFO	0x00300000	/* USB Device HS controller */
#define	ATMEL_BASE_OHCI		0x00400000	/* USB Host controller (OHCI) */
#define	ATMEL_BASE_EHCI		0x00500000	/* USB Host controller (EHCI) */
#define	ATMEL_BASE_AXI_MATRIX	0x00600000	/* AXI Maxtrix */
#define	ATMEL_BASE_DAP		0x00700000	/* DAP */
#define	ATMEL_BASE_PTC		0x00800000	/* PTC */
#define	ATMEL_BASE_L2CC		0x00A00000	/* L2CC */

/* Other misc defines */
#define ATMEL_BASE_PMECC	(ATMEL_BASE_HSMC + 0x70)
#define ATMEL_BASE_PMERRLOC	(ATMEL_BASE_HSMC + 0x500)

#define AT91_PMECC		(ATMEL_BASE_PMECC - ATMEL_BASE_SYS)
#define AT91_PMERRLOC		(ATMEL_BASE_PMERRLOC - ATMEL_BASE_SYS)

#define	ATMEL_BASE_PIOB		(ATMEL_BASE_PIOA + 0x40)
#define	ATMEL_BASE_PIOC		(ATMEL_BASE_PIOB + 0x40)
#define	ATMEL_BASE_PIOD		(ATMEL_BASE_PIOC + 0x40)

/* SYSC spawns */
#define	ATMEL_BASE_RSTC		ATMEL_BASE_SYSC
#define	ATMEL_BASE_SHDC		(ATMEL_BASE_SYSC + 0x10)
#define	ATMEL_BASE_PIT		(ATMEL_BASE_SYSC + 0x30)
#define	ATMEL_BASE_WDT		(ATMEL_BASE_SYSC + 0x40)
#define	ATMEL_SYS_SCKCR		(ATMEL_BASE_SYSC + 0x50)
#define	ATMEL_BASE_RTCC		(ATMEL_BASE_SYSC + 0xb0)

#define ATMEL_BASE_SMC		(ATMEL_BASE_HSMC + 0x600)

/*
 * Other misc defines
 */
#define ATMEL_PIO_PORTS		4
#define CPU_HAS_PIO4
#define CPU_HAS_PCR
#define CPU_HAS_H32MXDIV

/* sama5d2 series chip id definitions */
#define ARCH_ID_SAMA5D2		0x8a5c08c0
#define ARCH_EXID_SAMA5D21CU	0x0000005a
#define ARCH_EXID_SAMA5D22CU	0x00000059
#define ARCH_EXID_SAMA5D22CN	0x00000069
#define ARCH_EXID_SAMA5D23CU	0x00000058
#define ARCH_EXID_SAMA5D24CX	0x00000004
#define ARCH_EXID_SAMA5D24CU	0x00000014
#define ARCH_EXID_SAMA5D26CU	0x00000012
#define ARCH_EXID_SAMA5D27CU	0x00000011
#define ARCH_EXID_SAMA5D27CN	0x00000021
#define ARCH_EXID_SAMA5D28CU	0x00000010
#define ARCH_EXID_SAMA5D28CN	0x00000020

#define cpu_is_sama5d2()	(get_chip_id() == ARCH_ID_SAMA5D2)
#define cpu_is_sama5d21cu()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D21CU))
#define cpu_is_sama5d22cu()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D22CU))
#define cpu_is_sama5d22cn()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D22CN))
#define cpu_is_sama5d23cu()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D23CU))
#define cpu_is_sama5d24cx()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D24CX))
#define cpu_is_sama5d24cu()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D24CU))
#define cpu_is_sama5d26cu()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D26CU))
#define cpu_is_sama5d27cu()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D27CU))
#define cpu_is_sama5d27cn()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D27CN))
#define cpu_is_sama5d28cu()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D28CU))
#define cpu_is_sama5d28cn()	(cpu_is_sama5d2() && \
		(get_extension_chip_id() == ARCH_EXID_SAMA5D28CN))

/*
 * No PMECC Galois table in ROM
 */
#define NO_GALOIS_TABLE_IN_ROM

#ifndef __ASSEMBLY__
unsigned int get_chip_id(void);
unsigned int get_extension_chip_id(void);
unsigned int has_lcdc(void);
char *get_cpu_name(void);
#endif

/*
 * No PMECC Galois table in ROM
 */
#define NO_GALOIS_TABLE_IN_ROM

#ifndef __ASSEMBLY__
unsigned int get_chip_id(void);
unsigned int get_extension_chip_id(void);
unsigned int has_lcdc(void);
char *get_cpu_name(void);
#endif

#endif
