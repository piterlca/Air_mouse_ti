#include <stdint.h>
#include <stdlib.h>

#include <msp430fr4133.h>

#include "../generalDefs.h"
#include "../I2C/eusci_b_i2c.h"
#include "../USCI_I2C/i2c_MasterHiLevel.h"
#include "../I2C/i2c_hilev.h"

#define EUSCIB_BASEADDR 0x540

I2C0* I2C;

I2C0* I2C_HiLevelInit(uint8_t InputBufLen, uint8_t OutputBufLen)
{

    i2c_LL_init();

	I2C = (I2C0*)calloc(1, sizeof(I2C0));

	I2C->InputBufLength = InputBufLen;

	I2C->OutputBufLength = OutputBufLen;

	I2C->InputBuffer = (int8_t*)calloc(I2C->InputBufLength, sizeof(int8_t) );

	I2C->OutputBuffer = (uint8_t*)calloc(I2C->OutputBufLength, sizeof(uint8_t) );

	I2C->TransmissionInProgress = FALSE;

	return I2C;
}

void I2C_send(int8_t NumberOfBytes, uint8_t SendStop)
{
	uint16_t i = 0;

	EUSCI_B_I2C_masterSendStart(EUSCIB_BASEADDR);

	for(i = 0; i < NumberOfBytes; ++i)
	{
		EUSCI_B_I2C_masterSendMultiByteNext(	EUSCIB_BASEADDR, I2C->OutputBuffer[i]	);
	}


	if(TRUE == SendStop) i2c_stop(EUSCIB_BASEADDR);
	else 				 i2c_repstart(EUSCIB_BASEADDR);
}

void I2C_recv(int8_t NumberOfBytesToBeRcvd, uint8_t SendStop)
{
	uint16_t bytectr = 0;

	EUSCI_B_I2C_masterReceiveStart(EUSCIB_BASEADDR);

	for(bytectr = 0; bytectr < NumberOfBytesToBeRcvd; ++bytectr)
	{
		if(bytectr == (NumberOfBytesToBeRcvd - 1))
		{
			if(TRUE == SendStop)
				{
				i2c_stop(EUSCIB_BASEADDR);
				}
			else 				 i2c_repstart(EUSCIB_BASEADDR);
		}

        while(!(UCB0IFG & UCRXIFG))
        {
            ;
        }

		I2C->InputBuffer[bytectr] = EUSCI_B_I2C_masterReceiveMultiByteNext(EUSCIB_BASEADDR);


	}


}

void I2C_SelectSlaveDevice(uint8_t deviceAddr)
{
	I2C->currentSlaveAddr = deviceAddr;
}


void i2c_trial(void)
{
	EUSCI_B_I2C_masterSendSingleByte(	EUSCIB_BASEADDR, 0b01001000	);
}

