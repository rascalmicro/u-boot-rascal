/*
 * Copyright (C) 2015 Atmel Corporation
 *		      Bo Shen <voice.shen@atmel.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#define ACT8865_SYS_CONTROL0	0x00
#define ACT8865_SYS_CONTROL1	0x01

#define ACT8865_REG1_CONFIG0	0x20
#define ACT8865_REG1_CONFIG1	0x21
#define ACT8865_REG1_CONTROL	0x22

#define ACT8865_REG2_CONFIG0	0x30
#define ACT8865_REG2_CONFIG1	0x31
#define ACT8865_REG2_CONTROL	0x32

#define ACT8865_REG3_CONFIG0	0x40
#define ACT8865_REG3_CONFIG1	0x41
#define ACT8865_REG3_CONTROL	0x42

#define ACT8865_REG4_CONFIG0	0x50
#define ACT8865_REG4_CONTROL	0x51

#define ACT8865_REG5_CONFIG0	0x54
#define ACT8865_REG5_CONTROL	0x55

#define ACT8865_REG6_CONFIG0	0x60
#define ACT8865_REG6_CONTROL	0x61

#define ACT8865_REG7_CONFIG0	0x64
#define ACT8865_REG7_CONTROL	0x65

#define ACT8865_OUTPUT_ENABLE	(0x01 << 7)

#define ACT8865_I2C_ADDR	0x5B

enum act8865_ldo {
	ACT8865_LDO_REG4 = 4,
	ACT8865_LDO_REG5,
	ACT8865_LDO_REG6,
	ACT8865_LDO_REG7,
};

enum act8865_volt {
	ACT8865_1V2_VOLT = 0x18,
	ACT8865_1V8_VOLT = 0x24,
	ACT8865_2V5_VOLT = 0x31,
	ACT8865_3V3_VOLT = 0x39,
};

int act8865_enable_ldo_output(enum act8865_ldo ldo, enum act8865_volt volt);
int act8865_i2c_interface_accessable(void);
int act8865_disable_i2c_interface(void);
