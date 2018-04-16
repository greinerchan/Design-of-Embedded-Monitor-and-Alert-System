
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
#include "gpio.h"

void delay(unsigned int num)
{
  unsigned int i,j;
	for(i = 0;i < num;i++)
	{
    j = 1000;		
	  while(j--);
	}
}

int main (void)
{	
	periph_init();
	while(1)
	{
//		GPIO_SetActive(LED4_PORT, LED4_PIN);
//    delay(500);
//		GPIO_SetInactive(LED4_PORT, LED4_PIN);
//		delay(500);		
		GPIO_SetActive(LED4_PORT, LED4_PIN);
		GPIO_SetInactive(LED6_PORT, LED6_PIN);
    delay(500);
		GPIO_SetActive(LED5_PORT, LED5_PIN);
		GPIO_SetInactive(LED4_PORT, LED4_PIN);
		delay(500);
		GPIO_SetActive(LED6_PORT, LED6_PIN);
		GPIO_SetInactive(LED5_PORT, LED5_PIN);
		delay(500);
  }
}

