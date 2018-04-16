
#include "i2c_eeprom.h"
#include "i2c_func.h"
#include "uart.h"

void mpu_init1(void)
{
  i2c_eeprom_init(0x69, I2C_FAST, I2C_7BIT_ADDR, I2C_1BYTE_ADDR);
	
	i2c_eeprom_write_byte(0x6b,0x80);
	delay_ms(100);
	i2c_eeprom_write_byte(0x6b,0x00);

	i2c_eeprom_write_byte(0x1b,0x18);

	i2c_eeprom_write_byte(0x1c,0x18);

	i2c_eeprom_write_byte(0x1a,0x03);

	i2c_eeprom_write_byte(0x19,0x13);

}

void delay_ms(int num)
{
  unsigned int i = 80*num;
	while(i--)
	{

  }
}

void get_mpu_id(unsigned char *data)
{
  *data = i2c_eeprom_read_byte(0x75);
}

void get_mpu_accel(short int data_read[6])
{
	unsigned char data[6] = {0},data_g[6] = {0};
  short int accel_x,accel_y,accel_z,g_x,g_y,g_z;
  i2c_eeprom_read_data(data,0x3b,6);
  accel_x = (data[0] << 8) + data[1];
  accel_y = (data[2] << 8) + data[3];
  accel_z = (data[4] << 8) + data[5];
  data_read[0] = accel_x/204;
  data_read[1] = accel_y/204;
  data_read[2] = accel_z/204;
  i2c_eeprom_read_data(data_g,0x43,6);
  g_x = (data_g[0] << 8) + data_g[1];
  g_y = (data_g[2] << 8) + data_g[3];
  g_z = (data_g[4] << 8) + data_g[5];
  data_read[3] = g_x/16;
  data_read[4] = g_y/16;
  data_read[5] = g_z/16;
}



void oled_init(void)
{
  
}

