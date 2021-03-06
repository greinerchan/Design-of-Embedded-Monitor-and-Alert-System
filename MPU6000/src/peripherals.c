/**
 ****************************************************************************************
 *
 * @file peripherals.c
 *
 * @brief Peripherals initialization fucntions
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
#include "global_io.h"
#include <core_cm0.h>
#include "peripherals.h"

#include "i2c_func.h"
#include "gpio.h"
#include "uart_func.h"
#include "uart.h"
#include "gpio_func.h"
 /**
 ****************************************************************************************
 * @brief Enable pad's and peripheral clocks assuming that peripherals' power domain is down.
 *        The Uart and SPi clocks are set. 
 * 
 ****************************************************************************************
 */
void periph_init(void)  // set i2c, spi, uart, uart2 serial clks
{
    // system init
	SetWord16(CLK_AMBA_REG, 0x00); 				// set clocks (hclk and pclk ) 16MHz
	SetWord16(SET_FREEZE_REG,FRZ_WDOG);			// stop watch dog	
	SetBits16(SYS_CTRL_REG,PAD_LATCH_EN,1);  	// open pads
	SetBits16(SYS_CTRL_REG,DEBUGGER_ENABLE,1);  // open debugger
	SetBits16(PMU_CTRL_REG, PERIPH_SLEEP,0);  	// exit peripheral power down
	// Power up peripherals' power domain
    SetBits16(PMU_CTRL_REG, PERIPH_SLEEP, 0);
    while (!(GetWord16(SYS_STAT_REG) & PER_IS_UP));  
  uart_init();
	//Init pads
	set_pad_functions();
     
} 
 

void set_pad_functions(void)       
{
	GPIO_ConfigurePin(LED4_PORT, LED4_PIN, OUTPUT, PID_GPIO, false);
	GPIO_ConfigurePin(LED5_PORT, LED5_PIN, OUTPUT, PID_GPIO, false);
	GPIO_ConfigurePin(LED6_PORT, LED6_PIN, OUTPUT, PID_GPIO, false);
	GPIO_ConfigurePin(BUTTON2_PORT, BUTTON2_PIN, INPUT, PID_GPIO, false);
	GPIO_ConfigurePin(BUTTON3_PORT, BUTTON3_PIN, INPUT, PID_GPIO, false);
	GPIO_ConfigurePin(BEEP_PORT, BEEP_PIN, OUTPUT, PID_GPIO, false);
	GPIO_ConfigurePin(MOTOR_PORT, MOTOR_PIN, OUTPUT, PID_GPIO, false);
	
	GPIO_ConfigurePin(UART1_PORT, UART1_PIN_TX, OUTPUT, PID_UART1_TX, false);
	GPIO_ConfigurePin(UART1_PORT, UART1_PIN_RX, INPUT, PID_UART1_RX, false);
	
	GPIO_ConfigurePin(I2C_PORT, I2C_PIN_SCL, OUTPUT, PID_I2C_SCL, false);
	GPIO_ConfigurePin(I2C_PORT, I2C_PIN_SDA, OUTPUT, PID_I2C_SDA, false);
} 













