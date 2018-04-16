
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

void gpio_int(void)
{
  SetWord16(GPIO_IRQ0_IN_SEL_REG,0x0012);
	SetWord16(GPIO_IRQ1_IN_SEL_REG,0x0013);
	SetWord16(GPIO_DEBOUNCE_REG,0x0310);
	SetWord16(GPIO_INT_LEVEL_CTRL_REG,0x0303);
}

int main (void)
{	
	periph_init();
	gpio_int();
	NVIC_SetPriority(GPIO0_IRQn,1);
	NVIC_SetPriority(GPIO1_IRQn,2);
	NVIC_EnableIRQ(GPIO0_IRQn);
	NVIC_EnableIRQ(GPIO1_IRQn);
	while(1);
}

void GPIO0_Handler(void)
{
	GPIO_SetActive(LED4_PORT, LED4_PIN);
  SetWord16(GPIO_RESET_IRQ_REG,0x0001);
}

void GPIO1_Handler(void)
{
	GPIO_SetInactive(LED4_PORT, LED4_PIN);
  SetWord16(GPIO_RESET_IRQ_REG,0x0002);
}
