#ifndef __TIMER_H__
#define __TIMER_H__

void Timer0_Init_1(void);
void Timer0_Init_2(void);
void timer0_SetCounter(unsigned int Value);
unsigned int Timer0_GetCounter();
void Timer0_Run(unsigned char flag);
#endif
