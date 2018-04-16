
#ifndef _GPIO_FUNC_H_
#define _GPIO_FUNC_H_

#define LED4_PORT    GPIO_PORT_2
#define LED4_PIN     GPIO_PIN_1

#define LED5_PORT    GPIO_PORT_2
#define LED5_PIN     GPIO_PIN_2

#define LED6_PORT    GPIO_PORT_0
#define LED6_PIN     GPIO_PIN_7

#define BUTTON2_PORT    GPIO_PORT_2
#define BUTTON2_PIN     GPIO_PIN_3

#define BUTTON3_PORT    GPIO_PORT_2
#define BUTTON3_PIN     GPIO_PIN_4

#define BEEP_PORT    GPIO_PORT_1
#define BEEP_PIN     GPIO_PIN_1

#define MOTOR_PORT   GPIO_PORT_0
#define MOTOR_PIN    GPIO_PIN_4

void led_on(unsigned char led_num);

void led_off(unsigned char led_num);

int button_chose(void);

void motor_on(void);

void motor_off(void);

void beep_on(void);

void beep_off(void);

#endif
