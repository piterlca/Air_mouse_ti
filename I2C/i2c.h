/*
 * i2c_api.h
 *
 *  Created on: 10 paü 2015
 *      Author: Domowy
 */

#ifndef I2C_I2C_H_
#define I2C_I2C_H_


#define ONE_MASTER 1


#define I2C_BOOL_t uint8_t
#define I2C_DATA_t int8_t
#define I2C_DATA_CTR_t uint8_t
#define I2C_ADDRESS_t uint16_t


typedef enum I2C_OPERATION_MODE{I2C_MASTER = 0, I2C_SLAVE = 1}I2C_OPERATION_MODE;

typedef enum I2C_STATUS{I2C_STATUS_OK = 0, I2C_STATUS_TX_DATA_OVERWRITTEN = 1}I2C_STATUS;

enum{TRANSMIT = 0, RECEIVE = 1};

struct i2c_handle;
typedef struct i2c_handle* i2c_str;


/* ******************** 						I2C PUBLIC API									**********/

typedef struct i2c_msg_str
{
	uint8_t* i2c_buffer;
	uint8_t i2c_buffer_length;
	uint8_t	 generate_stop_after_transmission : 1;
	uint8_t  i2c_op_mode : 1;
	uint16_t destination_address;
}i2c_msg_str;

typedef struct i2c_init_str
{
	I2C_OPERATION_MODE 				op_mode;
	I2C_ADDRESS_t 					own_address;
	uint8_t							i2c_clock_val;
	uint8_t							tx_buffer_size;
	uint8_t							rx_buffer_size;
}i2c_init_str;

void i2c_send(i2c_str i2c_h, i2c_msg_str* msg);
void i2c_enable(i2c_str i2c_h);
i2c_str i2c_init(i2c_init_str* i2c_init);

#endif /* I2C_I2C_H_ */
