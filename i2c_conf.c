#include <stdint.h>
#include "I2C/i2c.h"

#include "i2c_conf.h"

void initialize_i2c(void)
{
	i2c_str i2c_h;
	i2c_msg_str msg;
	uint8_t tab[2];

	i2c_init_str i2c;
	i2c.i2c_clock_val = 15;
	i2c.op_mode = I2C_MASTER;
	i2c.own_address = 0;
	i2c.rx_buffer_size = 6;
	i2c.tx_buffer_size = 2;

	i2c_h = i2c_init(&i2c);


	msg.destination_address = 0b1101000;
	msg.generate_stop_after_transmission = 1;
	msg.i2c_buffer = (uint8_t*)&tab;
	msg.i2c_buffer_length = 2;
	msg.i2c_op_mode = I2C_MASTER;

	tab[0] = 0x68;
	tab[1] = 0x10;

	i2c_enable(i2c_h);

	i2c_send(i2c_h, &msg);

}
