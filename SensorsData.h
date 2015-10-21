/*
 * SensorsData.c
 *
 *  Created on: May 5, 2015
 *      Author: Piotr
 */

#ifndef SENSORSDATA_C_
#define SENSORSDATA_C_



typedef struct TriDimData{
	int16_t x;
	int16_t y;
	int16_t z;
}TriDimData;

typedef struct MPUSensor{
	uint8_t ID;
	uint8_t AccOn;
	uint8_t GyroOn;
	TriDimData* RawAcc;
	TriDimData* RawGyro;
}MPUSensor;

TriDimData processedGyro, processedAcc;

typedef enum {axisX, axisY, axisZ}Axes;

#endif /* SENSORSDATA_C_ */
