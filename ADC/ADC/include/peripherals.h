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

#define LED4_PORT    GPIO_PORT_2
#define LED4_PIN     GPIO_PIN_1

#define LED5_PORT    GPIO_PORT_2
#define LED5_PIN     GPIO_PIN_2

#define LED6_PORT    GPIO_PORT_0
#define LED6_PIN     GPIO_PIN_7 
 
void set_pad_functions(void);        // set gpio port function mode
void periph_init(void) ;
 
#endif
