#ifndef _OLED_H
#define _OLED_H
#include "stdint.h"
#include "stdbool.h"

void OLED_init(void);

void OLED_FILL(void);

void OLED_open(void);

void OLED_close(void);

void OLED_step_numb(uint16_t step_numb);

void OLED_temp_dis(void);

void OLED_func1(void);

void OLED_func2(void);

void OLED_func3(void);

void OLED_func4(void);

void OLED_time(uint8_t time_dis[6]);

void OLED_data(uint8_t data_dis[8]);

void OLED_day(uint8_t weekday);


#endif // _OLED_H
