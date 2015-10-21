#ifndef MPU_6050_H_
#define MPU_6050_H_

#include <stdint.h>

#include "../SensorsData.h"

extern MPUSensor MPU6050;

void MPU_init(uint8_t AccOn, uint8_t GyroOn, uint8_t SampleRateDivider);

void MPU_GetAccData();

void MPU_GetGyroData();

void ConvertToStructure(int8_t* RawData, TriDimData* mpudata);



#endif /* MPU_6050_H_ */


// You're gonna need:
// I2C
// UART
