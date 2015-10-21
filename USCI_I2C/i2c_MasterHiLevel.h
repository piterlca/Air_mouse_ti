
#ifndef USI_I2C_I2C_MASTERHILEVEL_H_
#define USI_I2C_I2C_MASTERHILEVEL_H_

#define STOP TRUE
#define NO_STOP FALSE

typedef struct I2C0{
	uint8_t currentSlaveAddr;
	int8_t* InputBuffer;
	uint8_t* OutputBuffer;
	uint8_t OutputBufLength;
	uint8_t InputBufLength;
	uint8_t TransmissionInProgress;
}I2C0;

extern I2C0* I2C;

I2C0* I2C_HiLevelInit(uint8_t InputBufLen, uint8_t OutputBufLen);

void I2C_send(int8_t NumberOfBytes, uint8_t SendStop);

void I2C_recv(int8_t NumberOfBytes, uint8_t SendStop);

void I2C_SelectSlaveDevice(uint8_t deviceAddr);

void i2c_trial(void);

#endif /* USI_I2C_I2C_MASTERHILEVEL_H_ */
