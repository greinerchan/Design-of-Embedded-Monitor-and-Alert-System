
#ifndef _I2C_FUNC_H_
#define _I2C_FUNC_H_

#define I2C_PORT    GPIO_PORT_1
#define I2C_PIN_SCL     GPIO_PIN_2
#define I2C_PIN_SDA     GPIO_PIN_3

void mpu_init1(void);

void delay_ms(int num);

void get_mpu_id(unsigned char *data);

void get_mpu_accel(short int data_read[3]);

#endif
