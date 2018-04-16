
#include "gpio.h"
#include "gpio_func.h"


void led_on(unsigned char led_num)
{
  switch(led_num)
	{
    case 4:GPIO_SetActive(LED4_PORT, LED4_PIN);
			break;
		case 5:GPIO_SetActive(LED5_PORT, LED5_PIN);
			break;
		case 6:GPIO_SetActive(LED6_PORT, LED6_PIN);
			break;
		default:
			break;
  }
}

void led_off(unsigned char led_num)
{
  switch(led_num)
	{
		case 4:GPIO_SetInactive(LED4_PORT, LED4_PIN);
			break;
		case 5:GPIO_SetInactive(LED5_PORT, LED5_PIN);
			break;
		case 6:GPIO_SetInactive(LED6_PORT, LED6_PIN);
			break;
		default:
			break;
  }
}

int button_chose(void)
{
	if(GPIO_GetPinStatus( BUTTON2_PORT, BUTTON2_PIN ))
	{
		while(GPIO_GetPinStatus( BUTTON2_PORT, BUTTON2_PIN ));
		return 2;
	}
	if(GPIO_GetPinStatus( BUTTON3_PORT, BUTTON3_PIN ))
	{
		while(GPIO_GetPinStatus( BUTTON3_PORT, BUTTON3_PIN ));
		return 3;
	}
	return 0;
}

void beep_on(void)
{
  GPIO_SetActive(BEEP_PORT, BEEP_PIN);
}

void beep_off(void)
{
  GPIO_SetInactive(BEEP_PORT, BEEP_PIN);
}

void motor_on(void)
{
  GPIO_SetActive(MOTOR_PORT, MOTOR_PIN);
}

void motor_off(void)
{
  GPIO_SetInactive(MOTOR_PORT, MOTOR_PIN);
}
