#include "TaskMgr.h"
#include "MPU-6050/MPU-6050.h"
#include "generalDefs.h"
volatile States state = IDLE;
volatile States last_state = REPORT;

void cycle()
{
	for(;;)
	{
		switch(state)
		{
			case MEASURE:
			{
				if(MPU6050.AccOn == TRUE)	MPU_GetAccData();
				if(MPU6050.GyroOn == TRUE)	MPU_GetGyroData();
				last_state = state;
				state = IDLE;
				break;
			}

			case REPORT:
			{
				if(MPU6050.AccOn == TRUE)
				{
					//FilterData(MPU6050.AccData, KalmanForAcc);
					//UART_print(MPU6050.AccData);
				}
				if(MPU6050.GyroOn == TRUE)
				{
					//FilterData(MPU6050.GyroData, KalmanForGyro);
					//UART_print(MPU6050.GyroData);
				}
				
				//ProcessToExecution(	MPU6050.GyroData, MPU6050.AccData, NULL	);
				
				//printf("%d\t%d\t%d\n", outputBuffer[1], outputBuffer[2], outputBuffer[3]);
				
				last_state = state;
				state = IDLE;
				break;
			}
			
			case IDLE:
				break;
		}
	}
}

/*void UART_print(MPUData* sensorData)
{
	if(sensorData == MPU6050.AccData)	printf("A");
	
	else if(sensorData == MPU6050.GyroData) 	printf("G");
	
	printf("%d %d %d\n", sensorData->x, sensorData->y, sensorData->z);
}
*/
