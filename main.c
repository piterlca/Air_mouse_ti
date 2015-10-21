#include <msp430.h>
#include "generalDefs.h"
#include "MPU-6050/MPU-6050.h"
#include "USCI_I2C/i2c_MasterHiLevel.h"
#include "TaskMgr.h"
#include "TimerInit.h"
#include "ClkSetting.h"
//#include "I2C/i2c.h"
#include "i2c_conf.h"

int main(void) {

	WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode


    initialize_i2c();

    // to activate previously configured port settings
    //I2C_HiLevelInit(16, 16);

//    i2c_trial();
    //setClks();

    //i2c_init();

    //MPU_init(FALSE, TRUE, 0x20);

   // timerInit(0xFF);

    //MPU_GetGyroData();

    /*i2c_h->rx_buf_size_b = 6;
    i2c_h->tx_buf_size_b = 2;
    //MPU_GetGyroData();

    i2c_init(i2c_h);


    i2c_h->op_mode = I2C_MASTER;

    i2c_enable(i2c_h);

    i2c_h->tx_buf[0] = 0x6B;
    i2c_h->tx_buf[1] = 0x10;
    i2c_h->n_bytes_to_be_sent = 2;
    i2c_h->dest_address = 0b1101000;
    i2c_h->generate_stop_at_the_end = 0;
	i2c_send(i2c_h);*/


	//i2c_send_stop();

//    MPU_GetAccData();
    for(;;)
    {
    	//cycle();
    }
}
