
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
#include "pwm.h"

void timer_init(void)
{
	set_tmr_enable(CLK_PER_REG_TMR_ENABLED);

	set_tmr_div(CLK_PER_REG_TMR_DIV_8);

	timer0_init(TIM0_CLK_FAST, PWM_MODE_ONE, TIM0_CLK_DIV_BY_10);

	timer0_set(65530, 0, 0);
	
	timer0_enable_irq();

	timer0_start();
}


int main (void)
{	
	periph_init();
	
	timer_init();
	
	while(1)
	{

  }
}

