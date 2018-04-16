
#include "global_io.h"
#include "gpio.h"
#include <core_cm0.h>
#include "uart_test.h"
#include "attm_db.h"
#include "ke_config.h"
#include "prf_utils.h"
#include "streamdatad.h"
#include "prf_utils.h"
#include "streamdatah.h"
#include "gattc_task.h"

void uart_init1(void)
{
	SetBits16(CLK_PER_REG, UART1_ENABLE, 1);  	// enable  clock for UART 1

	SetWord16(UART_LCR_REG, 0x80); // set bit to access DLH and DLL register
	SetWord16(UART_IER_DLH_REG,(UART_BAUDRATE_115K2&0xFF>>8));//set high byte
	SetWord16(UART_RBR_THR_DLL_REG,UART_BAUDRATE_115K2&0xFF);//set low byte
	SetWord16(UART_LCR_REG,UART_DATALENGTH_8|UART_PARITY_NONE|UART_STOPBITS_1);
	SetBits16(UART_MCR_REG, UART_SIRE, 0);  // mode 0 for normal , 1 for IRDA
	SetWord16(UART_IIR_FCR_REG,1);  // enable fifo  
	SetBits16(UART_IER_DLH_REG,ERBFI_dlh0,1);  // IER access, disable interrupt for available data
	NVIC_SetPriority(UART_IRQn,1);
	NVIC_EnableIRQ(UART_IRQn);
}

char uart_receive_byte(void){
	do{
	}while((GetWord16(UART_LSR_REG)&0x01)==0);	// wait until serial data is ready 
	return 0xFF&GetWord16(UART_RBR_THR_DLL_REG);	// read from receive data buffer
}

void uart_send_byte(char ch){
	while((GetWord16(UART_LSR_REG)&0x20)==0);	// read status reg to check if THR is empty
	SetWord16(UART_RBR_THR_DLL_REG,(0xFF&ch)); // write to THR register
	return;
}

void printf_string(char * str){
	while(*str!=0){	      // while not reach the last string character
		uart_send_byte(*str); // send next string character
		str++;
	}
}

char rx_data[20];
unsigned int rx_cnt=0;
void UART_Handler(void)
{
  if((GetWord16(UART_IIR_FCR_REG)&0x0f) == 0x04)
	{
		struct streamdatah_env_tag *streamdatah_env = PRF_CLIENT_GET_ENV(TASK_GATTC, streamdatah);
		rx_data[rx_cnt++] = 0xFF&GetWord16(UART_RBR_THR_DLL_REG);
		if(rx_cnt==20)
		{	
	    prf_gatt_write(&streamdatah_env->con_info, streamdatah_env->streamdatah.chars[STREAMDATAD_ENABLE_CHAR].val_hdl, (unsigned char *)rx_data,20, GATTC_WRITE_NO_RESPONSE);
			rx_cnt = 0;
    }
		else if(rx_data[rx_cnt-1]=='\n')
		{
			prf_gatt_write(&streamdatah_env->con_info, streamdatah_env->streamdatah.chars[STREAMDATAD_ENABLE_CHAR].val_hdl, (unsigned char *)rx_data,(rx_cnt-2), GATTC_WRITE_NO_RESPONSE);
			rx_cnt = 0;
    }
	}
}


