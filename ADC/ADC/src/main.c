
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

#include "adc.h"
#include "gpio.h"
int adc_data = 0;

int main (void)
{	
	periph_init();
	
	adc_init(GP_ADC_SE, 0);
	
	adc_enable_channel(ADC_CHANNEL_P01);

	while(1)
	{
		adc_data = adc_get_sample();
		if(adc_data > 800)
		{    
			GPIO_SetActive( GPIO_PORT_2, GPIO_PIN_1 );
			GPIO_SetActive( GPIO_PORT_2, GPIO_PIN_2 );
			GPIO_SetActive( GPIO_PORT_0, GPIO_PIN_7 );
		}
		else if(adc_data > 500)
		{
			GPIO_SetInactive(GPIO_PORT_2, GPIO_PIN_1);
			GPIO_SetActive( GPIO_PORT_2, GPIO_PIN_2 );
			GPIO_SetActive( GPIO_PORT_0, GPIO_PIN_7 );
		}
		else if(adc_data > 200)
		{
			GPIO_SetInactive(GPIO_PORT_2, GPIO_PIN_1);
			GPIO_SetInactive( GPIO_PORT_2, GPIO_PIN_2 );
			GPIO_SetActive( GPIO_PORT_0, GPIO_PIN_7 );
		}
		else
		{
			GPIO_SetInactive(GPIO_PORT_2, GPIO_PIN_1);
			GPIO_SetInactive( GPIO_PORT_2, GPIO_PIN_2 );
			GPIO_SetInactive( GPIO_PORT_0, GPIO_PIN_7 );
		}
  }
}









