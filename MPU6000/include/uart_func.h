
#ifndef _UART_FUNC_H_
#define _UART_FUNC_H_

#define UART1_PORT GPIO_PORT_2
#define UART1_PIN_TX  GPIO_PIN_8
#define UART1_PIN_RX  GPIO_PIN_9

void uart_title(void);

void uart_mpu6050(short int data[6]);

#endif
