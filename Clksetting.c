#include <msp430fr4133.h>

void setClks(void)
{
	CSCTL4 |= SELA;
}


