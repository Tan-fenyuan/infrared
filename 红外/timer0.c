#include "timer0.h"
#include <REGX52.H>
void Timer0_Init_1(void)
{
	TMOD &= 0xF0; // 设置定时器模式
	TMOD |= 0x01; // 设置定时器模式
	TL0 = 0xCD;	  // 设置定时初始值
	TH0 = 0xD4;	  // 设置定时初始值
	TF0 = 0;	  // 清除TF0标志
	TR0 = 1;	  // 定时器0开始计时
	ET0 = 1;	  // 使能定时器0中断
	EA = 1;
	PT0 = 0;
	PT0H = 0;
}

// void Timer0_Init()
// {
//     //TMOD = 0x01; // 16位计数器
//     TMOD&=0xF0;
//     TMOD |= 0x01;
//     TF0 = 0;
//     TR0 = 1;           // 允许T0开始计数
//     TH0 = 64535 / 256; // 高8位
//     TL0 = 64535 % 256; // 低8位
//     ET0 = 1;           // 允许溢出中断
//     EA = 1;            // 开放中断
//     PT0 = 0;
//     PT0H = 0;
// }
// void Timer2_Init(void)		//1毫秒@11.0592MHz
// {
// 	T2MOD = 0;				//初始化模式寄存器
// 	T2CON = 0;				//初始化控制寄存器
// 	TL2 = 0x66;				//设置定时初始值
// 	TH2 = 0xFC;				//设置定时初始值
// 	RCAP2L = 0x66;			//设置定时重载值
// 	RCAP2H = 0xFC;			//设置定时重载值
// 	TR2 = 1;				//定时器2开始计时
// }

// unsigned int T_count;
// void Timer0_Routine() interrupt 1
// {
//     TH0 = 65545 / 256; // 高8位
//     TL0 = 65545 % 256; // 低8位
//     T_count++;
//     if (T_count >= 1000)
//     {
//         P2_0 = ~P2_0;
//     }
// }
// void Timer0_Isr(void) interrupt 1
// {
// 	static unsigned int T_count;
// 	TL0 = 0xCD; // 设置定时初始值
// 	TH0 = 0xD4; // 设置定时初始值
// 	T_count++;
// 	if (T_count >= 30) // 83
// 	{
// 		T_count = 0;
// 		if (ledMode == 0)
// 		{
// 			P2 = _crol_(P2, 1); // 左移
// 		}
// 		if (ledMode == 1)
// 		{
// 			P2 = _cror_(P2, 1); // 右移
// 		}
// 	}
// }
void Timer0_Init_2(void)
{
	TMOD &= 0xF0; // 设置定时器模式
	TMOD |= 0x01; // 设置定时器模式
	TL0 = 0;	  // 设置定时初始值
	TH0 = 0;	  // 设置定时初始值
	TF0 = 0;	  // 清除TF0标志
	TR0 = 0;	  // 定时器0开始计时
}
void timer0_SetCounter(unsigned int Value)
{
	TH0 = Value / 256;
	TL0 = Value % 256;
}
unsigned int Timer0_GetCounter()
{
	return (TH0 << 8) | TL0;
}
void Timer0_Run(unsigned char flag)
{
	TR0 = flag;

}