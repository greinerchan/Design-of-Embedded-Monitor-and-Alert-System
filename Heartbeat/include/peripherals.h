/**
 ****************************************************************************************
 *
 * @file peripherals.h
 *
 * @brief Peripherals initialization fucntions headers
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
#include <stdint.h>

#ifndef PERIPHERAL_H_INCLUDED
#define PERIPHERAL_H_INCLUDED

#define HR_PORT  GPIO_PORT_2
#define HR_PIN_PWR   GPIO_PIN_0
#define HR_PIN_CNT   GPIO_PIN_7

#define OLED_PORT         GPIO_PORT_0
#define OLED_PIN_SCLK     GPIO_PIN_0
#define OLED_PIN_SDIN     GPIO_PIN_6
#define OLED_PIN_CS       GPIO_PIN_2

#define OLED_PORT_CD      GPIO_PORT_1
#define OLED_PIN_CD       GPIO_PIN_0

void set_pad_functions(void);        // set gpio port function mode
void periph_init(void) ;
 
#endif
