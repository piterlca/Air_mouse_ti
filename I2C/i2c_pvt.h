/* ********************				PRIVATE I2C STRUCTURES AND FUNCTION PROTOTYPES				************/
#define SET_I2C_PIN_FUNCTIONS (P5SEL0 |= (1<<3) | (1<<2)) // configure pin functions



typedef struct i2c_handle
{
	I2C_OPERATION_MODE	 			op_mode;
	I2C_ADDRESS_t 					own_address;
	I2C_DATA_CTR_t					n_bytes_to_be_sent;
	I2C_DATA_CTR_t					n_bytes_to_be_rcvd;
	volatile I2C_DATA_CTR_t			data_ctr;
	I2C_BOOL_t						generate_stop_at_the_end;	//determines if STOP condition is generated, when 0 == data_ctr
	volatile I2C_BOOL_t				bus_busy;
	ring_buffer*					txbuf;
	ring_buffer*					rxbuf;
}i2c_handle;

static void i2c_enable_pvt(i2c_handle* i2c_h);
static void i2c_send_pvt(i2c_handle* i2c_h, i2c_msg_str* msg);
