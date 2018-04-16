
#include "uart.h"
#include "uart_func.h"

void uart_title(void)
{
	printf_string("\n\r\n\r********************************************************************");
	printf_string("\n\r************************    ������Ŷ�    **************************");
	printf_string("\n\r********************    Board-DA14580-V1.0    **********************");
	printf_string("\n\r*******************    ����:www.mooband.net    *********************");
	printf_string("\n\r**************    �Ա�:shop115904315.taobao.com     ****************");
	printf_string("\n\r******************     �ٷ�Q QȺ: 193836402      *******************");
	printf_string("\n\r********************************************************************");
	printf_string("\n\r************************     MPU_TEST     **************************");
	printf_string("\n\r********************************************************************\n\r");
}

void uart_mpu6050(short int data[6])
{
	unsigned char data_print[6];
  printf_string("\n\r  ���ٶ�ֵ��");
	
	printf_string("\n\r X�᣺");
	if(data[0]<0)
  {
	  data_print[0] = '-';
    data[0] = -data[0];
	}
  else
  {
    data_print[0] = '+';
  }		
	data_print[1] = data[0]/100 + 0x30;
	data_print[2] = data[0]%100/10 + 0x30;
	data_print[3] = '.';
	data_print[4] = data[0]%10 + 0x30;
	print_nbytes(data_print, 5);
	
	printf_string("      Y�᣺");
	if(data[1]<0)
  {
	  data_print[0] = '-';
    data[1] = -data[1];
	}
  else
  {
    data_print[0] = '+';
  }		
	data_print[1] = data[1]/100 + 0x30;
	data_print[2] = data[1]%100/10 + 0x30;
	data_print[3] = '.';
	data_print[4] = data[1]%10 + 0x30;
	print_nbytes(data_print, 5);
	
	printf_string("      Z�᣺");
	if(data[2]<0)
  {
	  data_print[0] = '-';
    data[2] = -data[2];
	}
  else
  {
    data_print[0] = '+';
  }		
	data_print[1] = data[2]/100 + 0x30;
	data_print[2] = data[2]%100/10 + 0x30;
	data_print[3] = '.';
	data_print[4] = data[2]%10 + 0x30;
	print_nbytes(data_print, 5);
	
	printf_string("\n\r  ���ٶ�ֵ��");
	
	printf_string("\n\r X�᣺");
	if(data[3]<0)
  {
	  data_print[0] = '-';
    data[3] = -data[3];
	}
  else
  {
    data_print[0] = '+';
  }		
	data_print[1] = data[3]/1000 + 0x30;
	data_print[2] = data[3]%1000/100 + 0x30;
	data_print[3] = data[3]%100/10 + 0x30;
	data_print[4] = '.';
	data_print[5] = data[3]%10 + 0x30;
	print_nbytes(data_print, 6);
	
	printf_string("      Y�᣺");
	if(data[4]<0)
  {
	  data_print[0] = '-';
    data[4] = -data[4];
	}
  else
  {
    data_print[0] = '+';
  }		
	data_print[1] = data[4]/1000 + 0x30;
	data_print[2] = data[4]%1000/100 + 0x30;
	data_print[3] = data[4]%100/10 + 0x30;
	data_print[4] = '.';
	data_print[5] = data[4]%10 + 0x30;
	print_nbytes(data_print, 6);
	
	printf_string("      Z�᣺");
	if(data[5]<0)
  {
	  data_print[0] = '-';
    data[5] = -data[5];
	}
  else
  {
    data_print[0] = '+';
  }		
	data_print[1] = data[5]/1000 + 0x30;
	data_print[2] = data[5]%1000/100 + 0x30;
	data_print[3] = data[5]%100/10 + 0x30;
	data_print[4] = '.';
	data_print[5] = data[5]%10 + 0x30;
	print_nbytes(data_print, 6);
	
	
}

