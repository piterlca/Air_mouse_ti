/*
 * i2c.c
 *
 *  Created on: 8 paü 2015
 *      Author: Piotr
 */
#include <msp430fr4133.h>
#include "i2c_definitions.h"

#define I2C_BOOL_t uint8_t
#define I2C_STATUS uint8_t
#define I2C_OPERATION_MODE_t uint8_t
#define I2C_ADDRESS_t uint16_t
#define I2C_DATA_t int8_t
#define I2C_DATA_CTR_t uint8_t


typedef struct i2c_handle
{
	I2C_OPERATION_MODE_t 	op_mode;
	I2C_ADDRESS_t 			own_address;
	I2C_ADDRESS_t 			dest_address;
	I2C_DATA_t*				tx_buf;
	I2C_DATA_t*				rx_buf;
	I2C_DATA_CTR_t			data_ctr;
	I2C_BOOL_t				is_stop_generated;	//determines if STOP condition is generated, when 0 == data_ctr
};

void i2c_init(void)
{
	UCB0CTL1 |= UCSWRST;

	SET_I2C_PIN_FUNCTIONS;

	UCB0CTLW0 	|= UCMODE_3
				| UCSSEL0
				| UCSSEL1  ;

	if(I2C_MASTER == i2c_h->op_mode)
	{
		UCB0CTLW0 |= UCMST | UCTR;
	}
	else
	{
		UCB0CTLW0 &= ~UCMST & ~UCTR;
	}

	UCB0CTL1 &= ~UCSWRST;
}

void i2c_send(void)
{
	UCB0I2CSA = i2c_h->dest_address;

	UCB0CTLW0 |= UCTXSTT;
}

#pragma vector=USCI_B0_VECTOR

__interrupt void USCI_B0_ISR(void)
{
	if(UCB0IFG & UCTXIFG0)
	{
		if(i2c_h->data_ctr)
			UCB0TXBUF = i2c->data(i2c->bufsize - ctr);

		else if(i2c_h->generate_stop)
			UCB0CTLW0 |= UCTXSTP;

		else
			UCB0CTLW0 |= UCTXSTT;
	}
}

I2C_STATUS check_i2c_status(void)
{


}
