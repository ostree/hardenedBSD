/*-
 * Copyright (c) 2016 Emmanuel Vadot <manu@freeebsd.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef _AXP209REG_H_
#define	_AXP209REG_H_

/* Power State Register */
#define	AXP2XX_PSR		0x00
#define	AXP2XX_PSR_ACIN		0x80
#define	AXP2XX_PSR_ACIN_SHIFT	7
#define	AXP2XX_PSR_VBUS		0x20
#define	AXP2XX_PSR_VBUS_SHIFT	5

/* Shutdown and battery control */
#define	AXP2XX_SHUTBAT		0x32
#define	AXP2XX_SHUTBAT_SHUTDOWN	0x80

/* Voltage/Current Monitor */
#define	AXP209_ACIN_VOLTAGE		0x56
#define	AXP209_ACIN_CURRENT		0x58
#define	AXP209_VBUS_VOLTAGE		0x5A
#define	AXP209_VBUS_CURRENT		0x5C
#define	AXP2XX_BAT_VOLTAGE		0x78
#define	AXP2XX_BAT_CHARGE_CURRENT	0x7A
#define	AXP2XX_BAT_DISCHARGE_CURRENT	0x7C

#define	AXP209_VOLT_STEP	1700
#define	AXP2XX_BATVOLT_STEP	1100
#define	AXP209_ACCURRENT_STEP	625
#define	AXP209_VBUSCURRENT_STEP	375
#define	AXP2XX_BATCURRENT_STEP	500

/* Temperature monitor */
#define	AXP209_TEMPMON		0x5e
#define	AXP209_TEMPMON_MIN	1447	/* -144.7C */
#define	AXP221_TEMPMON_MIN	2437	/* -243.7C */

#define	AXP221_TEMPMON		0x56

/* Sensors conversion macros */
#define	AXP209_SENSOR_H(a)	((a) << 4)
#define	AXP209_SENSOR_L(a)	((a) & 0xf)
#define	AXP209_SENSOR_BAT_H(a)	((a) << 5)
#define	AXP209_SENSOR_BAT_L(a)	((a) & 0x1f)

#define	AXP209_0C_TO_K		2732

/* ADC Sensors */
#define	AXP2XX_ADC_ENABLE1	0x82
#define	AXP209_ADC_ENABLE2	0x83

#define	AXP2XX_ADC1_BATVOLT	(1 << 7)
#define	AXP2XX_ADC1_BATCURRENT	(1 << 6)
#define	AXP209_ADC1_ACVOLT	(1 << 5)
#define	AXP221_ADC1_TEMP	(1 << 5)
#define	AXP209_ADC1_ACCURRENT	(1 << 4)
#define	AXP209_ADC1_VBUSVOLT	(1 << 3)
#define	AXP209_ADC1_VBUSCURRENT	(1 << 2)
#define	AXP221_ADC1_TS_PIN	(1 << 0)

#define	AXP209_ADC2_TEMP	(1 << 7)

/* Interrupt related registers */
#define	AXP2XX_IRQ1_ENABLE	0x40
#define	AXP2XX_IRQ1_STATUS	0x48
#define	 AXP2XX_IRQ1_AC_OVERVOLT	(1 << 7)
#define	 AXP2XX_IRQ1_AC_CONN		(1 << 6)
#define	 AXP2XX_IRQ1_AC_DISCONN		(1 << 5)
#define	 AXP2XX_IRQ1_VBUS_OVERVOLT	(1 << 4)
#define	 AXP2XX_IRQ1_VBUS_CONN		(1 << 3)
#define	 AXP2XX_IRQ1_VBUS_DISCONN	(1 << 2)
#define	 AXP2XX_IRQ1_VBUS_LOW		(1 << 1)

#define	AXP2XX_IRQ2_ENABLE	0x41
#define	AXP2XX_IRQ2_STATUS	0x49
#define	 AXP2XX_IRQ2_BATT_CONN			(1 << 7)
#define	 AXP2XX_IRQ2_BATT_DISCONN		(1 << 6)
#define	 AXP2XX_IRQ2_BATT_CHARGE_ACCT_ON	(1 << 5)
#define	 AXP2XX_IRQ2_BATT_CHARGE_ACCT_OFF	(1 << 4)
#define	 AXP2XX_IRQ2_BATT_CHARGING		(1 << 3)
#define	 AXP2XX_IRQ2_BATT_CHARGED		(1 << 2)
#define	 AXP2XX_IRQ2_BATT_TEMP_OVER		(1 << 1)
#define	 AXP2XX_IRQ2_BATT_TEMP_LOW		(1 << 0)

#define	AXP2XX_IRQ3_ENABLE	0x42
#define	AXP2XX_IRQ3_STATUS	0x4A
#define	 AXP2XX_IRQ3_TEMP_OVER		(1 << 7)
#define	 AXP2XX_IRQ3_CHARGE_CURRENT_LOW	(1 << 6)
#define	 AXP2XX_IRQ3_DCDC2_LOW		(1 << 4)
#define	 AXP2XX_IRQ3_DCDC3_LOW		(1 << 3)
#define	 AXP2XX_IRQ3_LDO3_LOW		(1 << 2)
#define	 AXP2XX_IRQ3_PEK_SHORT		(1 << 1)
#define	 AXP2XX_IRQ3_PEK_LONG		(1 << 0)

#define	AXP2XX_IRQ4_ENABLE	0x43
#define	AXP2XX_IRQ4_STATUS	0x4B
#define	 AXP2XX_IRQ4_NOE_START		(1 << 7)
#define	 AXP2XX_IRQ4_NOE_SHUT		(1 << 6)
#define	 AXP2XX_IRQ4_VBUS_VALID		(1 << 5)
#define	 AXP2XX_IRQ4_VBUS_INVALID	(1 << 4)
#define	 AXP2XX_IRQ4_VBUS_SESSION	(1 << 3)
#define	 AXP2XX_IRQ4_VBUS_SESSION_END	(1 << 2)
#define	 AXP2XX_IRQ4_APS_LOW_1		(1 << 1)
#define	 AXP2XX_IRQ4_APS_LOW_2		(1 << 0)

#define	AXP2XX_IRQ5_ENABLE	0x44
#define	AXP2XX_IRQ5_STATUS	0x4C
#define	 AXP2XX_IRQ5_TIMER_EXPIRE	(1 << 7)
#define	 AXP2XX_IRQ5_PEK_RISE_EDGE	(1 << 6)
#define	 AXP2XX_IRQ5_PEK_FALL_EDGE	(1 << 5)
#define	 AXP2XX_IRQ5_GPIO3	(1 << 3)
#define	 AXP2XX_IRQ5_GPIO2	(1 << 2)
#define	 AXP2XX_IRQ5_GPIO1	(1 << 1)
#define	 AXP2XX_IRQ5_GPIO0	(1 << 0)

#define	AXP2XX_IRQ_ACK		0xff

/* GPIOs registers */
#define	AXP2XX_GPIO_FUNC_MASK		0x7

#define	AXP2XX_GPIO_FUNC_DRVLO		0x0
#define	AXP2XX_GPIO_FUNC_DRVHI		0x1
#define	AXP2XX_GPIO_FUNC_INPUT		0x2

#define	AXP2XX_GPIO0_CTRL	0x90
#define	AXP2XX_GPIO1_CTRL	0x92
#define	AXP209_GPIO2_CTRL	0x93
#define	AXP2XX_GPIO_STATUS	0x94

/* Regulators registers */
#define	AXP209_POWERCTL			0x12
#define	 AXP209_POWERCTL_LDO3		(1 << 6)
#define	 AXP209_POWERCTL_DCDC2		(1 << 4)
#define	 AXP209_POWERCTL_LDO4		(1 << 3)
#define	 AXP209_POWERCTL_LDO2		(1 << 2)
#define	 AXP209_POWERCTL_DCDC3		(1 << 1)

#define	AXP221_POWERCTL_1		0x10
#define	 AXP221_POWERCTL1_ALDO2		(1 << 7)
#define	 AXP221_POWERCTL1_ALDO1		(1 << 6)
#define	 AXP221_POWERCTL1_DCDC5		(1 << 5)
#define	 AXP221_POWERCTL1_DCDC4		(1 << 4)
#define	 AXP221_POWERCTL1_DCDC3		(1 << 3)
#define	 AXP221_POWERCTL1_DCDC2		(1 << 2)
#define	 AXP221_POWERCTL1_DCDC1		(1 << 1)
#define	 AXP221_POWERCTL1_DC5LDO	(1 << 0)

#define	AXP221_POWERCTL_2		0x12
#define	 AXP221_POWERCTL2_DC1SW		(1 << 7)
#define	 AXP221_POWERCTL2_DLDO4		(1 << 6)
#define	 AXP221_POWERCTL2_DLDO3		(1 << 5)
#define	 AXP221_POWERCTL2_DLDO2		(1 << 4)
#define	 AXP221_POWERCTL2_DLDO1		(1 << 3)
#define	 AXP221_POWERCTL2_ELDO3		(1 << 2)
#define	 AXP221_POWERCTL2_ELDO2		(1 << 1)
#define	 AXP221_POWERCTL2_ELDO1		(1 << 0)

#define	AXP221_POWERCTL_3		0x14
#define	 AXP221_POWERCTL3_ALDO3		(1 << 7)

#define	AXP209_REG_DCDC2_VOLTAGE	0x23
#define	AXP209_REG_DCDC3_VOLTAGE	0x27
#define	AXP209_REG_LDO24_VOLTAGE	0x28
#define	AXP209_REG_LDO3_VOLTAGE		0x29

#define	AXP221_REG_DLDO1_VOLTAGE	0x15
#define	AXP221_REG_DLDO2_VOLTAGE	0x16
#define	AXP221_REG_DLDO3_VOLTAGE	0x17
#define	AXP221_REG_DLDO4_VOLTAGE	0x18
#define	AXP221_REG_ELDO1_VOLTAGE	0x19
#define	AXP221_REG_ELDO2_VOLTAGE	0x1A
#define	AXP221_REG_ELDO3_VOLTAGE	0x1B
#define	AXP221_REG_DC5LDO_VOLTAGE	0x1C
#define	AXP221_REG_DCDC1_VOLTAGE	0x21
#define	AXP221_REG_DCDC2_VOLTAGE	0x22
#define	AXP221_REG_DCDC3_VOLTAGE	0x23
#define	AXP221_REG_DCDC4_VOLTAGE	0x24
#define	AXP221_REG_DCDC5_VOLTAGE	0x25
#define	AXP221_REG_DCDC23_VRC		0x27
#define	AXP221_REG_ALDO1_VOLTAGE	0x28
#define	AXP221_REG_ALDO2_VOLTAGE	0x29
#define	AXP221_REG_ALDO3_VOLTAGE	0x2A


enum axp2xx_sensor {
	AXP209_ACVOLT,
	AXP209_ACCURRENT,
	AXP209_VBUSVOLT,
	AXP209_VBUSCURRENT,
	AXP2XX_TEMP,
	AXP2XX_BATVOLT,
	AXP2XX_BATCHARGECURRENT,
	AXP2XX_BATDISCHARGECURRENT,
};

enum axp2xx_regulators {
	AXP209_REG_ID_DCDC2,
	AXP209_REG_ID_DCDC3,
	AXP209_REG_ID_LDO1,
	AXP209_REG_ID_LDO2,
	AXP209_REG_ID_LDO3,
	/* LDO4 is weird, need to find a correct way to handle it */
	/* AXP209_REG_ID_LDO4, */
	AXP209_REG_ID_LDO5,
	AXP221_REG_ID_DLDO1,
	AXP221_REG_ID_DLDO2,
	AXP221_REG_ID_DLDO3,
	AXP221_REG_ID_DLDO4,
	AXP221_REG_ID_ELDO1,
	AXP221_REG_ID_ELDO2,
	AXP221_REG_ID_ELDO3,
	AXP221_REG_ID_DC5LDO,
	AXP221_REG_ID_DCDC1,
	AXP221_REG_ID_DCDC2,
	AXP221_REG_ID_DCDC3,
	AXP221_REG_ID_DCDC4,
	AXP221_REG_ID_DCDC5,
	AXP221_REG_ID_ALDO1,
	AXP221_REG_ID_ALDO2,
	AXP221_REG_ID_ALDO3,
	AXP221_REG_ID_DC1SW,
};

#endif /* _AXP209REG_H_ */
