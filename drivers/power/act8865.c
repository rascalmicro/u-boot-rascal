/*
 * Copyright (C) 2015 Atmel Corporation
 *		      Bo Shen <voice.shen@atmel.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <i2c.h>
#include <act8865.h>

static int act8865_read(u32 reg, uchar *val)
{
	return i2c_read(ACT8865_I2C_ADDR, reg, 1, val, 1);
}

static int act8865_write(u32 reg, uchar val)
{
	return i2c_write(ACT8865_I2C_ADDR, reg, 1, &val, 1);
}

int act8865_i2c_interface_accessable(void)
{
	uchar val;

	/* Check the I2C interface is accessable or not */
	if (act8865_read(ACT8865_SYS_CONTROL0, &val)) {
		printf("I2C:   ACT8865 series can not be accessed\n");
		return 0;
	}

	return 1;
}

#ifdef CONFIG_ACT8865_DISABLE_I2C_INTERFACE
int act8865_disable_i2c_interface(void)
{
	/*
	 * As the ACT8865 don't have ID register, so we try one by one
	 * to disable the exist chips (303, 304, 305) in this series.
	 */

	/* Try to disable ACT8865QI303 */
	act8865_write(0x0B, 0xE9);
	act8865_write(0x02, 0x07);
	if (act8865_write(0x03, 0x01)) {
		printf("I2C:   ACT8865QI303 has been disabled\n");
		return 0;
	}

	/* Try to disable ACT8865QI304 */
	act8865_write(0x0B, 0xEE);
	act8865_write(0x02, 0x07);
	if (act8865_write(0x03, 0x01)) {
		printf("I2C:   ACT8865QI304 has been disabled\n");
		return 0;
	}

	/* Try to disable ACT8865QI305 */
	act8865_write(0x0B, 0xEE);
	act8865_write(0x02, 0x07);
	if (act8865_write(0x03, 0x01)) {
		printf("I2C:   ACT8865QI305 has been disabled\n");
		return 0;
	}

	printf("ACT8865: the chip can not be disabled\n");

	return 0;
}
#endif

int act8865_enable_ldo_output(enum act8865_ldo ldo, enum act8865_volt volt)
{
	u32 conf_reg, ctrl_reg;
	uchar val;

	switch (ldo) {
	case ACT8865_LDO_REG4:
		conf_reg = ACT8865_REG4_CONFIG0;
		ctrl_reg = ACT8865_REG4_CONTROL;
		break;

	case ACT8865_LDO_REG5:
		conf_reg = ACT8865_REG5_CONFIG0;
		ctrl_reg = ACT8865_REG5_CONTROL;
		break;

	case ACT8865_LDO_REG6:
		conf_reg = ACT8865_REG6_CONFIG0;
		ctrl_reg = ACT8865_REG6_CONTROL;
		break;

	case ACT8865_LDO_REG7:
		conf_reg = ACT8865_REG7_CONFIG0;
		ctrl_reg = ACT8865_REG7_CONTROL;
		break;
	default:
		error("I2C:   ACT8865 unsupported LDO\n");
		return -1;
	}

	/* Set the LDO output voltage */
	act8865_write(conf_reg, volt);
	/* Enable the LDO */
	act8865_read(ctrl_reg, &val);
	val |= ACT8865_OUTPUT_ENABLE;
	act8865_write(ctrl_reg, val);

	return 0;
}
