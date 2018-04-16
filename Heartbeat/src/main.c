
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
#include "spi.h"
#include "pwm.h"

#define LCD_USED 1
unsigned char hr_num = 0;
SPI_Pad_t spi_FLASH_CS_Pad;

#if (LCD_USED)
unsigned char heixin[][240] = {
0X00,0X00,0X00,0X00,0X00,0X00,0X80,0XC0,0XE0,0XE0,0XF0,0XF0,0XF0,0XF0,0XF0,0XF0,
0XF0,0XF0,0XF0,0XF0,0XE0,0XE0,0XC0,0X80,0XC0,0XC0,0XE0,0XF0,0XF0,0XF0,0XF0,0XF0,
0XF0,0XF0,0XF0,0XF0,0XF0,0XE0,0XE0,0XC0,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0XFC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0XF8,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X03,0X1F,0X3F,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0X1F,0X07,0X03,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X07,0X07,0X0F,0X1F,0X3F,0X7F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,
0X3F,0X1F,0X1F,0X0F,0X07,0X03,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0X03,0X03,0X07,0X0F,0X0F,0X0F,0X07,0X07,0X03,0X01,0X01,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,	
	
0X00,0X80,0XC0,0XF0,0XF8,0XF8,0XFC,0XFC,0XFE,0XFE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFE,0XFE,0XFE,0XFC,0XFC,0XF8,0XF0,0XF0,0XF8,0XF8,0XFC,0XFE,0XFE,0XFE,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0XFE,0XFE,0XFC,0XF8,0XF8,0XF0,0XC0,0X80,0X00,
0XFC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,
0X00,0X07,0X1F,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7F,0X1F,0X0F,0X01,
0X00,0X00,0X00,0X00,0X00,0X01,0X03,0X07,0X0F,0X1F,0X3F,0X7F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X7F,0X3F,0X1F,0X0F,0X07,0X03,0X01,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X01,0X03,
0X07,0X0F,0X0F,0X1F,0X3F,0X3F,0X7F,0XFF,0XFF,0X7F,0X3F,0X3F,0X1F,0X0F,0X0F,0X07,
0X03,0X01,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};

unsigned char hanzi[] = {
/*He   0 */
0xFC,0xFC,0x40,0x40,0x40,0xFC,0xFC,0x00,0xC0,0xE0,0xA0,0xA0,0xA0,0xE0,0xC0,0x00,
0x0F,0x0F,0x00,0x00,0x00,0x0F,0x0F,0x00,0x07,0x0F,0x08,0x08,0x08,0x0C,0x04,0x00,

/*ar   1 */
0x00,0xA0,0xA0,0xA0,0xE0,0xC0,0x00,0x00,0x20,0xE0,0xC0,0x60,0x20,0x60,0xC0,0x00,
0x07,0x0F,0x08,0x08,0x07,0x0F,0x08,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00,0x00,0x00,

/*tb   2 */
0x20,0x20,0xF8,0xFC,0x20,0x20,0x00,0x00,0x04,0xFC,0xFC,0x20,0x60,0xC0,0x80,0x00,
0x00,0x00,0x07,0x0F,0x08,0x0C,0x04,0x00,0x08,0x0F,0x07,0x08,0x08,0x0F,0x07,0x00,

/*ea   3 */
0xC0,0xE0,0xA0,0xA0,0xA0,0xE0,0xC0,0x00,0x00,0xA0,0xA0,0xA0,0xE0,0xC0,0x00,0x00,
0x07,0x0F,0x08,0x08,0x08,0x0C,0x04,0x00,0x07,0x0F,0x08,0x08,0x07,0x0F,0x08,0x00,

/*t    4 */
0x20,0x20,0xF8,0xFC,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x07,0x0F,0x08,0x0C,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*.    5 */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*Er   6 */
0x04,0xFC,0xFC,0x44,0xE4,0x0C,0x1C,0x00,0x20,0xE0,0xC0,0x60,0x20,0x60,0xC0,0x00,
0x08,0x0F,0x0F,0x08,0x08,0x0C,0x0E,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00,0x00,0x00,

/*ro   7 */
0x20,0xE0,0xC0,0x60,0x20,0x60,0xC0,0x00,0xC0,0xE0,0x20,0x20,0x20,0xE0,0xC0,0x00,
0x08,0x0F,0x0F,0x08,0x00,0x00,0x00,0x00,0x07,0x0F,0x08,0x08,0x08,0x0F,0x07,0x00,

/*r    8 */
0x20,0xE0,0xC0,0x60,0x20,0x60,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x08,0x0F,0x0F,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*:    9 */
0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x06,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};

unsigned char shuzi[] = {
	
/*--  ??:  0  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,
	
	/*--  ??:  1  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,

/*--  ??:  2  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x70,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00,

/*--  ??:  3  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x30,0x08,0x88,0x88,0x48,0x30,0x00,0x00,0x18,0x20,0x20,0x20,0x11,0x0E,0x00,

/*--  ??:  4  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x00,0xC0,0x20,0x10,0xF8,0x00,0x00,0x00,0x07,0x04,0x24,0x24,0x3F,0x24,0x00,

/*--  ??:  5  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0xF8,0x08,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x21,0x20,0x20,0x11,0x0E,0x00,

/*--  ??:  6  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0xE0,0x10,0x88,0x88,0x18,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x11,0x0E,0x00,

/*--  ??:  7  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x38,0x08,0x08,0xC8,0x38,0x08,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,

/*--  ??:  8  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00,

/*--  ??:  9  --*/
/*--  ??12;  ??????????:?x?=8x16   --*/
0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x00,0x31,0x22,0x22,0x11,0x0F,0x00,

};

void Delay_ms(unsigned long value)
{
	unsigned int i,j;
    for (i=0;i<value;i++)
		for (j=0;j<500;j++);
}

void Init_ST7567()
{
	lcd_cs_low();
	Delay_ms(100);

       Write_Command(0xe2);	  //SOFT RESET//寄存器复位
Delay_ms(100);
       Write_Command(0xaf);	  //0xaf显示器开
       Write_Command(0x2f);	  //0x2f升压电路,电压管理电路,
	   	   
       Write_Command(0x25);	   //0x20-0x27为V5电压内部电阻调整设置 

       Write_Command(0x81);	   // SET EV 调对比度
       Write_Command(0x1F);	   //0x01-0x3f电量寄存器设置模式

       Write_Command(0xa0);	   //0xa0为Segment正向,0xa1 为Segment反向
	   	   
       Write_Command(0xc8);	   //0xc0正向扫描,0xc8反射扫描

       Write_Command(0xa6);	   // //0xa6正向显示,0xa7反向显示
       Write_Command(0xa4);	   // //0xa4正常显示,0xa5全屏点亮

 //      Write_ST7567_COM(0xac);	   //
 //      Write_ST7567_COM(0x00);	

       Write_Command(0xf8);	   // //背压比设置
       Write_Command(0x00);		 //00--10
			 
}



void clear_screen(unsigned char xx)
{
unsigned int i,j;
for(i=0;i<8;i++)
	{
		Write_Command(0xb0+i);	 //SET PAGE 0---8
	    Write_Command(0x10);	 //SET COLUMN MSB
		Write_Command(0x00);	  //SET CLUMN LSB
		for(j=0;j<128;j++)
		{
			Write_Data(xx);
		}
	 }
}

void display_hanzi1616(unsigned char num, unsigned char x, unsigned char y)
{
  unsigned int i,j,adressd=0;

	for(i=x;i<(x+2);i++)
	{
		Write_Command(0xb0+i);
		Write_Command(0x10+(y>>4));
		Write_Command(0x00+(y&0x0f));
		for(j=0;j<16;j++)
		{
			Write_Data(hanzi[adressd+32*num]);
			adressd++;
		}
	}
}

void display_shuzi816(unsigned char num, unsigned char x, unsigned char y)
{
  unsigned int i,j,adressd=0;

	for(i=x;i<(x+2);i++)
	{
		Write_Command(0xb0+i);
		Write_Command(0x10+(y>>4));
		Write_Command(0x00+(y&0x0f));
		for(j=0;j<8;j++)
		{
			Write_Data(shuzi[adressd+16*num]);
			adressd++;
		}
	}
}
	
void display_movie()
{
  unsigned int i,j,m,adressd=0;
	for(m = 0; m < 2; m++)
	{
		for(i=0;i<5;i++)
		{
			Write_Command(0xb0+i);
				Write_Command(0x12);
			Write_Command(0x00);
			for(j=0;j<48;j++)
			{
				Write_Data(heixin[m][adressd]);
				adressd++;
			}
		}
		adressd = 0;
		Delay_ms(1000);
	}
}

void icon_display(unsigned char num, unsigned char on_off)
{
  Write_Command(0xb8);
	
  Write_Command(0x10|(num>>4));
  Write_Command(num&0x0f);
	
	
	if(on_off)
	  Write_Data(0x00);
	else
		Write_Data(0x01);
}
#endif

void timer_init(void)
{
    //Enables TIMER0,TIMER2 clock
    set_tmr_enable(CLK_PER_REG_TMR_ENABLED);
    
    //Sets TIMER0,TIMER2 clock division factor to 8
    set_tmr_div(CLK_PER_REG_TMR_DIV_8);
    
    // initilalize PWM with the desired settings
    timer0_init(TIM0_CLK_FAST, PWM_MODE_ONE, TIM0_CLK_DIV_BY_10);
  
    // set pwm Timer0 On, Timer0 'high' and Timer0 'low' reload values
    timer0_set(65530, 0, 0);
    
    // enable SWTIM_IRQn irq
    timer0_enable_irq();
	
    // start pwm0
    //timer0_start();
	  timer0_stop();
}

void timer_callback(void)
{
  static unsigned char flag;
	flag++;
	if(flag == 90)
	{
    flag = 0;
		hr_num = hr_num<<1;
		if((hr_num > 120)|(hr_num < 45))
		{
      display_hanzi1616(0,6,0);
			display_hanzi1616(1,6,16);
			display_hanzi1616(2,6,32);
			display_hanzi1616(3,6,48);
			display_hanzi1616(4,6,64);
			display_hanzi1616(6,6,80);
			display_hanzi1616(7,6,96);
			display_hanzi1616(8,6,112);
    }
		else
		{
			display_hanzi1616(0,6,0);
	    display_hanzi1616(1,6,16);
			display_hanzi1616(2,6,32);
				display_hanzi1616(3,6,48);
			display_hanzi1616(4,6,64);
			display_hanzi1616(9,6,74);
		  display_shuzi816((hr_num/10), 6, 86);
			display_shuzi816((hr_num%10), 6, 96);
	
		}
		hr_num = 0;
		timer0_stop();
		GPIO_SetInactive(HR_PORT, HR_PIN_PWR);
	  NVIC_DisableIRQ(GPIO0_IRQn);
  }
}

void gpio_int(void)
{
  SetWord16(GPIO_IRQ0_IN_SEL_REG,0x0016);
	SetWord16(GPIO_IRQ1_IN_SEL_REG,0x0013);
	SetWord16(GPIO_DEBOUNCE_REG,0x0310);
	SetWord16(GPIO_INT_LEVEL_CTRL_REG,0x0303);
}

unsigned char flag = 0;
int main (void)
{	
	periph_init();
	
	
	periph_init();
	timer_init();
	timer0_register_callback(timer_callback);
	spi_FLASH_CS_Pad.port = GPIO_PORT_0;
	spi_FLASH_CS_Pad.pin  = GPIO_PIN_3;
	spi_init(&spi_FLASH_CS_Pad, SPI_MODE_8BIT, SPI_ROLE_MASTER, SPI_CLK_IDLE_POL_LOW, SPI_PHA_MODE_0, SPI_MINT_DISABLE, SPI_XTAL_DIV_8);
  gpio_int();
	NVIC_SetPriority(GPIO0_IRQn,1);
	NVIC_SetPriority(GPIO1_IRQn,2);
	
	NVIC_EnableIRQ(GPIO1_IRQn);
#if (LCD_USED)
	Init_ST7567();
	Delay_ms(1000);
	clear_screen(0x00);
		
	icon_display(0,0);
	icon_display(10,0);
	icon_display(12,0);
	icon_display(16,0);
	icon_display(18,0);
	icon_display(20,0);
	icon_display(33,0);
	icon_display(46,0);
	icon_display(59,0);
	icon_display(74,0);
	icon_display(79,0);
	icon_display(87,0);
	icon_display(102,0);
	icon_display(116,0);
	icon_display(120,0);
	icon_display(123,0);
	icon_display(127,0);
	icon_display(125,0);
#endif
  flag = 1;
	while(1);
}

void GPIO0_Handler(void)
{
	if(flag)
	{
#if (LCD_USED)
	display_movie();
#endif
	hr_num++;
	}
  SetWord16(GPIO_RESET_IRQ_REG,0x0001);
}

void GPIO1_Handler(void)
{
	if(flag)
	{
	display_hanzi1616(0,6,0);
	display_hanzi1616(1,6,16);
	display_hanzi1616(2,6,32);
	display_hanzi1616(3,6,48);
	display_hanzi1616(4,6,64);
	display_hanzi1616(5,6,80);
	display_hanzi1616(5,6,96);
	display_hanzi1616(5,6,112);
	GPIO_SetActive(HR_PORT, HR_PIN_PWR);
	NVIC_EnableIRQ(GPIO0_IRQn);
	hr_num = 0;
	timer0_start();
	}
  SetWord16(GPIO_RESET_IRQ_REG,0x0002);
}
