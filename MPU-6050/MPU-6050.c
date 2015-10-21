#include <stdint.h>
#include <stdlib.h>

#include "../generalDefs.h"
#include "../SensorsData.h"
#include "../MPU-6050/MPU-6050.h"
#include "../USCI_I2C/i2c_MasterHiLevel.h"

#define NO_STOP FALSE
#define STOP TRUE

static const unsigned char MPUaddress = 0b1101000;

MPUSensor MPU6050;

static const enum{	
	INT_ENABLE = 0x38, 
	PWR_MGMT_1 = 0x6B, 
	PWR_MGMT_2 = 0x6C, 
	ACC_X_MSB = 0x3B, 
	GYRO_X_MSB = 0x43, 
	ACCEL_CONFIG = 0x1C,
	SMPRT_DIV = 0x19
} MPU_Registers;

void MPU_init(uint8_t AccOn, uint8_t GyroOn, uint8_t SampleRateDivider)
{
	MPU6050.ID = MPUaddress;
	if(	(MPU6050.AccOn = AccOn) == TRUE)
	{
		MPU6050.RawAcc = (TriDimData*)calloc(	1, sizeof(TriDimData)	);
	}
	
	if(	(MPU6050.GyroOn = GyroOn) == TRUE)	
	{
		MPU6050.RawGyro = (TriDimData*)calloc(	1, sizeof(TriDimData)	);
	}
	

	I2C_SelectSlaveDevice(MPU6050.ID);

	I2C->OutputBuffer[0] = PWR_MGMT_1;
	I2C->OutputBuffer[1] = 0x00;	// Operating mode = NORMAL
	I2C_send(2, NO_STOP);

	I2C->OutputBuffer[0] = SMPRT_DIV;
	I2C->OutputBuffer[1] = SampleRateDivider;
	I2C_send(2, NO_STOP);

	I2C->OutputBuffer[0] = INT_ENABLE;
	I2C->OutputBuffer[1] = 0x01; //enable data_Rdy interrupt for testing
	I2C_send(2, STOP);

	I2C->OutputBuffer[0] = I2C->OutputBuffer[1] = 0;
}

void MPU_GetAccData()
{
	I2C_SelectSlaveDevice(MPU6050.ID);
	I2C->OutputBuffer[0] = ACC_X_MSB;
	
	I2C_send(1, NO_STOP);
	
	I2C_SelectSlaveDevice(MPU6050.ID);
	I2C_recv(6, STOP);
	
	ConvertToStructure(I2C->InputBuffer, MPU6050.RawAcc);
}

void MPU_GetGyroData()
{
	I2C_SelectSlaveDevice(MPU6050.ID);
	I2C->OutputBuffer[0] = GYRO_X_MSB;
	
	I2C_send(1, NO_STOP);
	
	I2C_SelectSlaveDevice(MPU6050.ID);
	I2C_recv(6, STOP);
	
	ConvertToStructure(I2C->InputBuffer, MPU6050.RawGyro);
	
}

void ConvertToStructure(int8_t* RawData, TriDimData* mpudata)
{
	mpudata->x = ( RawData[0] << 8 | RawData[1] ) + 300;
	mpudata->y = ( RawData[2] << 8 | RawData[3] ) + 100;
	mpudata->z = ( RawData[4] << 8 | RawData[5] ) + 20;
}
