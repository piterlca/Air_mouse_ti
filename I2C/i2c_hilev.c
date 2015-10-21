#define __MSP430_HAS_EUSCI_Bx_

#include "eusci_b_i2c.h"
#include <stdlib.h>
#include <msp430fr4133.h>
#define EUSCIB_BASEADDR 0x540

EUSCI_B_I2C_initMasterParam* I2C_LL_params;


void i2c_LL_init()
{
	P5SEL0 |= (1<<3) | (1<<2); // configure pin functions

	I2C_LL_params = (EUSCI_B_I2C_initMasterParam*)calloc(	1, sizeof(EUSCI_B_I2C_initMasterParam)	);
	I2C_LL_params->selectClockSource = EUSCI_B_I2C_CLOCKSOURCE_SMCLK;
	I2C_LL_params->i2cClk = 8000;
	I2C_LL_params->dataRate = EUSCI_B_I2C_SET_DATA_RATE_100KBPS;

	I2C_LL_params->byteCounterThreshold = 100;
	I2C_LL_params->autoSTOPGeneration = EUSCI_B_I2C_NO_AUTO_STOP;

	EUSCI_B_I2C_initMaster(EUSCIB_BASEADDR, I2C_LL_params);

	EUSCI_B_I2C_setMode(EUSCIB_BASEADDR, EUSCI_B_I2C_TRANSMIT_MODE);

	EUSCI_B_I2C_enableInterrupt(EUSCIB_BASEADDR,
			EUSCI_B_I2C_TRANSMIT_INTERRUPT0 | EUSCI_B_I2C_RECEIVE_INTERRUPT0);

	EUSCI_B_I2C_setSlaveAddress(EUSCIB_BASEADDR, 0b1101000);
	UCB0BRW = 0x0F;
	EUSCI_B_I2C_enable(EUSCIB_BASEADDR);

}

