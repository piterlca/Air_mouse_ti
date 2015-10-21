/*
 * i2c.c

 *
 *  Created on: 8 paü 2015
 *      Author: Piotr
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <msp430fr4133.h>

#include "../generalDefs.h"

#include "../Ring_buffer/ring_buffer.h"

#include "i2c.h"
#include "i2c_pvt.h"

static inline i2c_handle* get_i2c_h(i2c_handle* i2c_h)
{
	static i2c_handle* i2c = NULL;

	if(NULL != i2c_h)
	{
		i2c = i2c_h;
		return NULL;
	}

	else
	{
		return i2c;
	}
}

void i2c_send(i2c_str i2c_h, i2c_msg_str* msg)
{
	add_element_to_buffer(i2c_h->txbuf, (void*)msg);

	i2c_send_pvt(i2c_h, msg);
}

i2c_msg_str* i2c_recv(i2c_handle* i2c_h)
{
	return read_element_from_buffer(i2c_h->rxbuf);
}

i2c_str i2c_init(i2c_init_str* i2c_init)
{
	i2c_handle* i2c_h = (i2c_handle*)malloc(sizeof(i2c_handle));
	memset(i2c_h, 0, sizeof(i2c_handle));

	i2c_h->rxbuf = init_ring_buffer(i2c_init->rx_buffer_size, sizeof(i2c_msg_str));
	i2c_h->txbuf = init_ring_buffer(i2c_init->tx_buffer_size, sizeof(i2c_msg_str));

	get_i2c_h(i2c_h);

	UCB0CTL1 |= UCSWRST;

	SET_I2C_PIN_FUNCTIONS;

	UCB0CTLW0 	|= UCMODE_3
				| UCSSEL1
				| UCSYNC;

	if(I2C_MASTER == i2c_h->op_mode)
	{
		UCB0CTLW0 |= UCMST | UCTR;
	}
	else
	{
		UCB0CTLW0 &= ~UCMST & ~UCTR;
	}

	UCB0BRW = 15;

	return i2c_h;
}

static void i2c_enable_pvt(i2c_handle* i2c_h)
{
	_EINT();

	UCB0CTL1 &= ~UCSWRST;

	UCB0IE =0b111111111;//|= UCTXIE0;
}

static void i2c_send_pvt(i2c_handle* i2c_h, i2c_msg_str* msg)
{
	UCB0I2CSA = msg->destination_address;

	while(i2c_h->bus_busy);

	if(!(UCB0STATW & UCBBUSY))
	{
		UCB0CTLW0 |= UCTXSTT;
		i2c_h->bus_busy = TRUE;
	}

#ifdef ONE_MASTER
	else
		UCB0CTLW0 |= UCTXSTP;
#endif
}



//TODO info 'bout msg len is in msg str, not in i2c_h str!!!
#pragma vector = USCI_B0_VECTOR
__interrupt void USCI_B0_ISR(void)
{
	i2c_handle* i2c_h = NULL;
	i2c_h = get_i2c_h(i2c_h);
	static volatile i2c_msg_str* msg = NULL;
	static volatile uint8_t data_ctr = 0;

	if(UCB0IFG & UCTXIFG0)
	{
		if(0 == data_ctr)
		msg = (i2c_msg_str*)read_element_from_buffer(i2c_h->txbuf);


		if(msg->i2c_buffer_length - data_ctr)
		{
			UCB0TXBUF = msg->i2c_buffer[data_ctr];

			++data_ctr;
		}
		else
		{
			if(msg->generate_stop_after_transmission)				UCB0CTLW0 |= UCTXSTP;
			else													UCB0CTLW0 |= UCTXSTT;

			data_ctr = 0;

			i2c_h->bus_busy = FALSE;
		}
	}

	if(UCB0IFG & UCNACKIFG)
	{
		UCB0CTLW0 |= UCTXSTP;
	}
}

I2C_STATUS check_i2c_status(void)
{
	return I2C_STATUS_OK;
}


void i2c_enable(i2c_str i2c_h)
{
	i2c_enable_pvt(i2c_h);
}
