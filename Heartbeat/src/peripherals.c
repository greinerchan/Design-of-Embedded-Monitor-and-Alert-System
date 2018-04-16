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
#include "gpio.h"  
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
  
	//Init pads
	set_pad_functions();
     
} 
 
 /**
 ****************************************************************************************
 * @brief set gpio port function mode
  * 
 ****************************************************************************************
 */
void set_pad_functions(void)       
{
  GPIO_ConfigurePin(HR_PORT, HR_PIN_PWR, OUTPUT, PID_GPIO,false);
	GPIO_ConfigurePin(HR_PORT, HR_PIN_CNT, INPUT, PID_GPIO,false);
	
	GPIO_ConfigurePin(OLED_PORT, OLED_PIN_CS, OUTPUT, PID_GPIO,false);
	GPIO_ConfigurePin(OLED_PORT_CD, OLED_PIN_CD, OUTPUT, PID_GPIO,false);
	GPIO_ConfigurePin(OLED_PORT, OLED_PIN_SCLK, OUTPUT, PID_SPI_CLK,false);
	GPIO_ConfigurePin(OLED_PORT, OLED_PIN_SDIN, OUTPUT, PID_SPI_DO,false);
} 

















