/*
 * Configuration settings for the SAMA5D2 Xplained board.
 *
 * Copyright (C) 2015 Atmel
 *		      Wenyou Yang <wenyou.yang@atmel.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <asm/hardware.h>

#define CONFIG_SYS_TEXT_BASE		0x26f00000

/* ARM asynchronous clock */
#define CONFIG_SYS_AT91_SLOW_CLOCK      32768
#define CONFIG_SYS_AT91_MAIN_CLOCK      12000000 /* from 12 MHz crystal */

#define CONFIG_ARCH_CPU_INIT

#ifndef CONFIG_SPL_BUILD
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_DISPLAY_CPUINFO

#define CONFIG_CMD_BOOTZ
#define CONFIG_OF_LIBFDT		/* Device Tree support */

#define CONFIG_SYS_GENERIC_BOARD

/* general purpose I/O */
#define CONFIG_AT91_GPIO

/* serial console */
#define CONFIG_ATMEL_USART
#define CONFIG_USART_BASE		ATMEL_BASE_UART1
#define CONFIG_USART_ID			ATMEL_ID_UART1

#define CONFIG_BOOTDELAY		3

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME

/* No NOR flash */
#define CONFIG_SYS_NO_FLASH

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>
#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_IMI
#undef CONFIG_CMD_LOADS
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_SETEXPR

/* SDRAM */
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_SDRAM_BASE           ATMEL_BASE_DDRCS
#define CONFIG_SYS_SDRAM_SIZE		0x20000000

#ifdef CONFIG_SPL_BUILD
#define CONFIG_SYS_INIT_SP_ADDR		0x210000
#else
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_SDRAM_BASE + 4 * 1024 - GENERATED_GBL_DATA_SIZE)
#endif

#define CONFIG_SYS_LOAD_ADDR		0x22000000 /* load address */

/* SerialFlash */
#define CONFIG_CMD_SF

#ifdef CONFIG_CMD_SF
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_ATMEL
#define CONFIG_SPI_FLASH_STMICRO
#define CONFIG_SF_DEFAULT_BUS		0
#define CONFIG_SF_DEFAULT_CS		0
#define CONFIG_SF_DEFAULT_SPEED		30000000
#endif

/* MMC */
#define CONFIG_CMD_MMC

#ifdef CONFIG_CMD_MMC
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_SDHCI
#define CONFIG_ATMEL_SDHCI
#define CONFIG_ATMEL_SDHCI0
#ifndef CONFIG_ATMEL_QSPI
#define CONFIG_ATMEL_SDHCI1
#endif
#define CONFIG_SUPPORT_EMMC_BOOT
#endif

/* Software I2C */
#define CONFIG_CMD_I2C

#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_SOFT
#define CONFIG_SYS_I2C_SOFT_SPEED       50000
#define CONFIG_SOFT_I2C_GPIO_SCL        GPIO_PIN_PD(5)
#define CONFIG_SOFT_I2C_GPIO_SDA        GPIO_PIN_PD(4)
#define CONFIG_AT24MAC_ADDR		0x5c
#define CONFIG_AT24MAC_REG		0x9a

/* USB */
#define CONFIG_CMD_USB

#ifdef CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_ATMEL
#define CONFIG_SYS_USB_EHCI_MAX_ROOT_PORTS	3
#define CONFIG_USB_STORAGE
#endif

/* USB device */
#define CONFIG_USB_GADGET
#define CONFIG_USB_GADGET_DUALSPEED
#define CONFIG_USB_GADGET_ATMEL_USBA
#define CONFIG_USB_ETHER
#define CONFIG_USB_ETH_RNDIS
#define CONFIG_USBNET_MANUFACTURER      "Atmel SAMA5D2_XPlained"

#if defined(CONFIG_CMD_USB) || defined(CONFIG_CMD_MMC)
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION
#endif

/* Ethernet Hardware */
#define CONFIG_MACB
#define CONFIG_RMII
#define CONFIG_NET_RETRY_COUNT		20
#define CONFIG_MACB_SEARCH_PHY

/* LCD */
 #define CONFIG_LCD
#ifdef CONFIG_LCD
#define LCD_BPP				LCD_COLOR16
#define LCD_OUTPUT_BPP                  24
#define CONFIG_LCD_LOGO
#define CONFIG_LCD_INFO
#define CONFIG_LCD_INFO_BELOW_LOGO
#define CONFIG_SYS_WHITE_ON_BLACK
#define CONFIG_ATMEL_HLCD
#define CONFIG_ATMEL_LCD_RGB565
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#endif

#ifdef CONFIG_SYS_USE_SERIALFLASH
/* bootstrap + u-boot + env + linux in serial flash */
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_SPI_BUS	CONFIG_SF_DEFAULT_BUS
#define CONFIG_ENV_SPI_CS	CONFIG_SF_DEFAULT_CS
#define CONFIG_ENV_OFFSET       0x4000
#define CONFIG_ENV_SIZE         0x4000
#define CONFIG_ENV_SECT_SIZE    0x1000
#define CONFIG_BOOTCOMMAND      "sf probe 0; " \
				"sf read 0x21000000 0x60000 0xc000; " \
				"sf read 0x22000000 0x6c000 0x394000; " \
				"bootz 0x22000000 - 0x21000000"
#elif CONFIG_SYS_USE_MMC
/* bootstrap + u-boot + env in sd card */
#define CONFIG_ENV_IS_IN_FAT
#define CONFIG_FAT_WRITE
#define FAT_ENV_INTERFACE	"mmc"
/*
 * We don't specify the part number, if device 0 has partition table, it means
 * the first partition; it no partition table, then take whole device as a
 * FAT file system.
 */
#define FAT_ENV_DEVICE_AND_PART	"1"
#define FAT_ENV_FILE		"uboot.env"
#define CONFIG_ENV_SIZE		0x4000
#define CONFIG_BOOTCOMMAND	"fatload mmc 1:1 0x21000000 at91-sama5d2_xplained.dtb; " \
				"fatload mmc 1:1 0x22000000 zImage; " \
				"bootz 0x22000000 - 0x21000000"
#endif

#ifdef CONFIG_SYS_USE_MMC
#define CONFIG_BOOTARGS							\
	"console=ttyS0,57600 earlyprintk "				\
	"root=/dev/mmcblk1p2 rw rootwait"
#else
#define CONFIG_BOOTARGS							\
	"console=ttyS0,57600 earlyprintk "				\
	"mtdparts=atmel_nand:256k(bootstrap)ro,512k(uboot)ro,"		\
	"256K(env),256k(evn_redundent),256k(spare),"			\
	"512k(dtb),6M(kernel)ro,-(rootfs) "				\
	"rootfstype=ubifs ubi.mtd=7 root=ubi0:rootfs"
#endif

#define CONFIG_BAUDRATE			57600

#define CONFIG_SYS_PROMPT		"U-Boot> "
#define CONFIG_SYS_CBSIZE		256
#define CONFIG_SYS_MAXARGS		16
#define CONFIG_SYS_LONGHELP
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_HUSH_PARSER

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(4 * 1024 * 1024)


/* SPL */
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_TEXT_BASE		0x200000
#define CONFIG_SPL_MAX_SIZE		0x10000
#define CONFIG_SPL_BSS_START_ADDR	0x20000000
#define CONFIG_SPL_BSS_MAX_SIZE		0x80000
#define CONFIG_SYS_SPL_MALLOC_START	0x20080000
#define CONFIG_SYS_SPL_MALLOC_SIZE	0x80000

#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_GPIO_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT

#define CONFIG_SPL_BOARD_INIT
#define CONFIG_SYS_MONITOR_LEN		(512 << 10)

#ifdef CONFIG_SYS_USE_MMC
#define CONFIG_SPL_LDSCRIPT		arch/arm/cpu/at91-common/u-boot-spl.lds
#define CONFIG_SPL_MMC_SUPPORT
#define CONFIG_SYS_U_BOOT_MAX_SIZE_SECTORS	0x400
#define CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR 0x200
#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION	1
#define CONFIG_SPL_FS_LOAD_PAYLOAD_NAME		"u-boot.img"
#define CONFIG_SPL_FAT_SUPPORT
#define CONFIG_SPL_LIBDISK_SUPPORT

#elif CONFIG_SYS_USE_SERIALFLASH
#define CONFIG_SPL_SPI_SUPPORT
#define CONFIG_SPL_SPI_FLASH_SUPPORT
#define CONFIG_SPL_SPI_LOAD
#define CONFIG_SYS_SPI_U_BOOT_OFFS	0x20000
#endif

#endif
