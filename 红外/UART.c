#include "UART.h"

char buff;//存储接收到的数据

/// @brief 初始化
void UART_Init()
{
    SCON = 0x50; // 0101 0000 允许接受
    PCON |= 0x80;
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TL1 = 0xF4; // 0xF3 12Mhz    0xF4 11.0592MHz
    TH1 = 0xF4;
    ET1 = 0; // 禁止定时器 1中断
    TR1 = 1; // 启动定时器1
    // 使能中断
    EA = 1; // 开启中断
    ES = 1; // 开启串口中断
}
/// @brief 发送一个byte
/// @param Byte
void URAT_SendByte(unsigned char Byte)
{
    SBUF = Byte;
    while (TI == 0)
    {
        // do nothing
    }
    TI = 0;//软件复位1
}
/// @brief 返回接收到的数据
/// @return 接收的数据
/// @retval char buff
char UART_GetBuff()
{
    return buff;
}

// 中断函数转移
//recv
void UART_Routine() interrupt 4
{
    //如果有数据
    if (RI == 1)
    {
        buff = SBUF;

       
        RI = 0;//软件复位0
    }
}
