/*
 * MeasuringAndPresenting.h
 *
 *  Created on: Mar 21, 2015
 *      Author: Piotr
 */

#ifndef MEASURINGANDPRESENTING_H_
#define MEASURINGANDPRESENTING_H_

#include "MPU-6050/MPU-6050.h"

typedef enum {MEASURE, REPORT, IDLE} States;
extern volatile States state;
extern volatile States last_state;

void cycle();

//void UART_print(MPUData* sensorData);

#endif /* MEASURINGANDPRESENTING_H_ */
