
 /*
 ****************************************************************************************
 *
 * @file DA14580_examples.c
 *
 * @brief DA14580 Peripheral Examples for DA14580 SDK
 *
 * Copyright (C) 2012. Dialog Semiconductor Ltd, unpublished work. This computer 
 * program includes Confidential, Proprietary Information and is a Trade Secret of 
 * Dialog Semiconductor Ltd.  All use, disclosure, and/or reproduction is prohibited 
 * unless authorized in writing. All Rights Reserved.
 *
 * <bluetooth.support@diasemi.com> and contributors.
 *
 ****************************************************************************************
 */
#include <stdio.h>
#include "global_io.h"
#include "peripherals.h"

#include "i2c_func.h"
#include "gpio_func.h"
#include "uart_func.h"
#include "motion.h"
#define  MPU_DMP  0
void delay(unsigned int num)
{
  unsigned int i,j;
	for(i=0;i<num;i++)
	{
    for(j=0;j<500;j++)
		{

    }
  }
}

short int data_read[6] = {0};
unsigned char data_who = 0;

int main (void)
{	
	periph_init();
  uart_title();
#if (MPU_DMP)
	mpu_init1();
	get_mpu_id(&data_who);

	while(1)
	{
		get_mpu_accel(data_read);
    uart_mpu6050(data_read);
		delay(500);
	}
#else
	motion_init();
	while(1)
	{
    uart_dis();
//		delay(500);
  }
#endif	
}



