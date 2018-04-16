#include "OLED.h"
#include "i2c_eeprom.h"
#include "stdlib.h"
#include "zimo.h"
#include "gpio.h"
uint8_t zimo_buf[312];

void OLED_init()
{
  i2c_eeprom_init(0x3c, 2, 0, I2C_1BYTE_ADDR);
	i2c_eeprom_write_byte(0X00, 0xAE);
	i2c_eeprom_write_byte(0X00, 0x20);
	i2c_eeprom_write_byte(0X00, 0x10);
	i2c_eeprom_write_byte(0X00, 0xB0);
	i2c_eeprom_write_byte(0X00, 0xc8);
	i2c_eeprom_write_byte(0X00, 0x00);
	i2c_eeprom_write_byte(0X00, 0x10);
	i2c_eeprom_write_byte(0X00, 0x40);
	i2c_eeprom_write_byte(0X00, 0x81);
	i2c_eeprom_write_byte(0X00, 0x7f);
	i2c_eeprom_write_byte(0X00, 0xa1);//a1
	i2c_eeprom_write_byte(0X00, 0xa6);//a6
	i2c_eeprom_write_byte(0X00, 0xa8);
	i2c_eeprom_write_byte(0X00, 0x3F);
	i2c_eeprom_write_byte(0X00, 0xa4);//a4
	i2c_eeprom_write_byte(0X00, 0xd3);
	i2c_eeprom_write_byte(0X00, 0x00);
	i2c_eeprom_write_byte(0X00, 0xd5);
	i2c_eeprom_write_byte(0X00, 0xf0);
	i2c_eeprom_write_byte(0X00, 0xd9);
	i2c_eeprom_write_byte(0X00, 0x22);
	i2c_eeprom_write_byte(0X00, 0xda);
	i2c_eeprom_write_byte(0X00, 0x12);
	i2c_eeprom_write_byte(0X00, 0xdb);
	i2c_eeprom_write_byte(0X00, 0x40);
//	i2c_eeprom_write_byte(0X00, 0x8d);
//	i2c_eeprom_write_byte(0X00, 0x14);
	i2c_eeprom_write_byte(0X00, 0xaf);
//	while(i2c_eeprom_write_page(command_com, 0x00 , 26) == 26);
}

void OLED_open()
{
  i2c_eeprom_init(0x3c, 2, 0, I2C_1BYTE_ADDR);
	i2c_eeprom_write_byte(0x00, 0xaf);
}

void OLED_close()
{
  i2c_eeprom_init(0x3c, 2, 0, I2C_1BYTE_ADDR);
	i2c_eeprom_write_byte(0x00, 0xAE);
}



void OLED_FILL()
{
	OLED_open();
	unsigned char m,n;	
	for(m=0;m<8;m++)
	{
		i2c_eeprom_write_byte(0X00, 0xb0+m);//page0-page1	
		i2c_eeprom_write_byte(0x00, 0x00);		//low column start address
		i2c_eeprom_write_byte(0X00, 0x10);		//high column start address
		for(n=0;n<132;n++)
			{
				i2c_eeprom_write_byte(0x40, 0xff);
			}
	}
}

//功能函数1的子函数，显示总步数
void OLED_step_numb(uint16_t step_numb)
{
	uint8_t step_numb_dis[5];
  step_numb_dis[0] = step_numb/10000;
	step_numb_dis[1] = step_numb%10000/1000;
	step_numb_dis[2] = step_numb%1000/100;
	step_numb_dis[3] = step_numb%100/10;
	step_numb_dis[4] = step_numb%10;
	
	uint8_t *shuzi;
//  do{
//    shuzi	= (uint8_t *)malloc(192);
//  }while(shuzi == NULL);
	shuzi = zimo_buf;	

	
	i2c_eeprom_init(0x3c, 2, 0, I2C_1BYTE_ADDR);
		
	uint8_t i = 0,m = 0;
  i2c_eeprom_write_byte(0X00, 0xb2);
	i2c_eeprom_write_byte(0x00, 0x06);		//low column start address
	i2c_eeprom_write_byte(0X00, 0x14);		//high column start address
	for(m = 0; m < 5; m++)
	{
		for(i = 0; i < 8; i++)
		{
			i2c_eeprom_write_byte(0x40, *(shuzi+step_numb_dis[m]*16+i));
		}
  }
	i2c_eeprom_write_byte(0X00, 0xb3);
	i2c_eeprom_write_byte(0x00, 0x06);		//low column start address
	i2c_eeprom_write_byte(0X00, 0x14);		//high column start address
	for(m = 0;m < 5;m++)
	{
		for(i = 8; i < 16; i++)
		{
			i2c_eeprom_write_byte(0x40, *(shuzi+step_numb_dis[m]*16+i));
		}
  }
//	free(shuzi);
}





void OLED_time(uint8_t time_dis[6])
{
	i2c_eeprom_init(0x3c, 2, 0, I2C_1BYTE_ADDR);
	
	
	uint8_t i = 0;
  i2c_eeprom_write_byte(0X00, 0xb2);
	i2c_eeprom_write_byte(0x00, 0x01);		//low column start address
	i2c_eeprom_write_byte(0X00, 0x12);		//high column start address
	for(i = 0; i < 8; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[0]*16+i));
  }
	for(i = 0; i < 8; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[1]*16+i));
  }
	for(i = 0; i < 8; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+160+i));
  }
	for(i = 0; i < 8; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[2]*16+i));
  }
	for(i = 0; i < 8; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[3]*16+i));
  }
	for(i = 0; i < 8; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+160+i));
  }
	for(i = 0; i < 8; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[4]*16+i));
  }
	for(i = 0; i < 8; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[5]*16+i));
  }
	
	
	i2c_eeprom_write_byte(0X00, 0xb3);
	i2c_eeprom_write_byte(0x00, 0x01);		//low column start address
	i2c_eeprom_write_byte(0X00, 0x12);		//high column start address
	for(i = 8; i < 16; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[0]*16+i));
  }
	for(i = 8; i < 16; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[1]*16+i));
  }
	for(i = 8; i < 16; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+160+i));
  }
	for(i = 8; i < 16; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[2]*16+i));
  }
	for(i = 8; i < 16; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[3]*16+i));
  }
	for(i = 8; i < 16; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+160+i));
  }
	for(i = 8; i < 16; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[4]*16+i));
  }
	for(i = 8; i < 16; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi+time_dis[5]*16+i));
  }
//	free(shuzi);
}




void OLED_data(uint8_t data_dis[8])
{
	i2c_eeprom_init(0x3c, 2, 0, I2C_1BYTE_ADDR);
	
	uint8_t i;
  i2c_eeprom_write_byte(0X00, 0xb4);
	i2c_eeprom_write_byte(0x00, 0x01);		//low column start address
	i2c_eeprom_write_byte(0X00, 0x10);		//high column start address
  for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[0]*12+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[1]*12+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[2]*12+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[3]*12+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+120+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[4]*12+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[5]*12+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+120+i));
  }
  for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[6]*12+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[7]*12+i));
  }

	i2c_eeprom_write_byte(0X00, 0xb5);
	i2c_eeprom_write_byte(0x00, 0x01);		//low column start address
	i2c_eeprom_write_byte(0X00, 0x10);		//high column start address
  for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[0]*12+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[1]*12+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[2]*12+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[3]*12+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+120+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[4]*12+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[5]*12+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+120+i));
  }
  for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[6]*12+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(shuzi12+data_dis[7]*12+i));
  }
	
//	free(shuzi12);
	
}

void OLED_day(uint8_t weekday)
{	
	i2c_eeprom_init(0x3c, 2, 0, I2C_1BYTE_ADDR);
	
	uint8_t i,data_dis[3];
	switch(weekday)
	{
    case 1:data_dis[0] = 12;
		       data_dis[1] = 14;
		       data_dis[2] = 13;
		       break;
		case 2:data_dis[0] = 19;
		       data_dis[1] = 20;
		       data_dis[2] = 4;
		       break;
		case 3:data_dis[0] = 22;
		       data_dis[1] = 4;
		       data_dis[2] = 3;
		       break;
		case 4:data_dis[0] = 19;
		       data_dis[1] = 7;
		       data_dis[2] = 20;
		       break;
		case 5:data_dis[0] = 5;
		       data_dis[1] = 17;
		       data_dis[2] = 8;
		       break;
		case 6:data_dis[0] = 18;
		       data_dis[1] = 0;
		       data_dis[2] = 19;
		       break;
		case 7:data_dis[0] = 18;
		       data_dis[1] = 20;
		       data_dis[2] = 13;
		       break;
    default: break;
  }
	
  i2c_eeprom_write_byte(0X00, 0xb4);
	i2c_eeprom_write_byte(0x00, 0x01);		//low column start address
	i2c_eeprom_write_byte(0X00, 0x16);		//high column start address
  for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(zimu12+data_dis[0]*12+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(zimu12+data_dis[1]*12+i));
  }
	for(i = 0; i < 6; i++)
	{
    i2c_eeprom_write_byte(0x40, *(zimu12+data_dis[2]*12+i));
  }


	i2c_eeprom_write_byte(0X00, 0xb5);
	i2c_eeprom_write_byte(0x00, 0x01);		//low column start address
	i2c_eeprom_write_byte(0X00, 0x16);		//high column start address
  for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(zimu12+data_dis[0]*12+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(zimu12+data_dis[1]*12+i));
  }
	for(i = 6; i < 12; i++)
	{
    i2c_eeprom_write_byte(0x40, *(zimu12+data_dis[2]*12+i));
  }
//	free(zimu12);
	
}


