#include "timer0.h"
#include <REGX52.H>
void Timer0_Init_1(void)
{
	TMOD &= 0xF0; // ���ö�ʱ��ģʽ
	TMOD |= 0x01; // ���ö�ʱ��ģʽ
	TL0 = 0xCD;	  // ���ö�ʱ��ʼֵ
	TH0 = 0xD4;	  // ���ö�ʱ��ʼֵ
	TF0 = 0;	  // ���TF0��־
	TR0 = 1;	  // ��ʱ��0��ʼ��ʱ
	ET0 = 1;	  // ʹ�ܶ�ʱ��0�ж�
	EA = 1;
	PT0 = 0;
	PT0H = 0;
}

// void Timer0_Init()
// {
//     //TMOD = 0x01; // 16λ������
//     TMOD&=0xF0;
//     TMOD |= 0x01;
//     TF0 = 0;
//     TR0 = 1;           // ����T0��ʼ����
//     TH0 = 64535 / 256; // ��8λ
//     TL0 = 64535 % 256; // ��8λ
//     ET0 = 1;           // ��������ж�
//     EA = 1;            // �����ж�
//     PT0 = 0;
//     PT0H = 0;
// }
// void Timer2_Init(void)		//1����@11.0592MHz
// {
// 	T2MOD = 0;				//��ʼ��ģʽ�Ĵ���
// 	T2CON = 0;				//��ʼ�����ƼĴ���
// 	TL2 = 0x66;				//���ö�ʱ��ʼֵ
// 	TH2 = 0xFC;				//���ö�ʱ��ʼֵ
// 	RCAP2L = 0x66;			//���ö�ʱ����ֵ
// 	RCAP2H = 0xFC;			//���ö�ʱ����ֵ
// 	TR2 = 1;				//��ʱ��2��ʼ��ʱ
// }

// unsigned int T_count;
// void Timer0_Routine() interrupt 1
// {
//     TH0 = 65545 / 256; // ��8λ
//     TL0 = 65545 % 256; // ��8λ
//     T_count++;
//     if (T_count >= 1000)
//     {
//         P2_0 = ~P2_0;
//     }
// }
// void Timer0_Isr(void) interrupt 1
// {
// 	static unsigned int T_count;
// 	TL0 = 0xCD; // ���ö�ʱ��ʼֵ
// 	TH0 = 0xD4; // ���ö�ʱ��ʼֵ
// 	T_count++;
// 	if (T_count >= 30) // 83
// 	{
// 		T_count = 0;
// 		if (ledMode == 0)
// 		{
// 			P2 = _crol_(P2, 1); // ����
// 		}
// 		if (ledMode == 1)
// 		{
// 			P2 = _cror_(P2, 1); // ����
// 		}
// 	}
// }
void Timer0_Init_2(void)
{
	TMOD &= 0xF0; // ���ö�ʱ��ģʽ
	TMOD |= 0x01; // ���ö�ʱ��ģʽ
	TL0 = 0;	  // ���ö�ʱ��ʼֵ
	TH0 = 0;	  // ���ö�ʱ��ʼֵ
	TF0 = 0;	  // ���TF0��־
	TR0 = 0;	  // ��ʱ��0��ʼ��ʱ
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