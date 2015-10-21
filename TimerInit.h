/*
 * TimerInit.h
 *
 *  Created on: 30 maj 2015
 *      Author: Piotr
 */

#ifndef TIMERINIT_H_
#define TIMERINIT_H_

void timerInit(uint16_t compareValue);

__interrupt void Timer_A(void);


#endif /* TIMERINIT_H_ */
