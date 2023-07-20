#include <REGX52.H>
#include "IR.h"
#include "LCD.h"
#include "UART.h"

unsigned char Command; // 获取红外发过来的数据

void Init()
{
    IR_Init();
    LCD_Init();
    UART_Init();
}

char send_command; // 要发送的command

char recv_buff; // 存储由电脑发送到单片机的数据
void main()
{
    Init();
    LCD_ShowString(1, 1, "MSG:");
    while (1)
    {
        if (IR_GetDataFlag())
        {
            Command = IR_GetCommand();

            LCD_ShowHexNum(2, 1, Command, 2);
            if (Command == IR_RPT)
            {
                // 如果RPT键被按下,则通过串口发送到电脑端
                URAT_SendByte(send_command);
            }
            if (Command == IR_USD)
            {
                // 如果USD被按下,则通过串口接收数据并显示
                recv_buff = UART_GetBuff();
                LCD_ShowHexNum(2,6,recv_buff,2);
            }
            send_command = Command;
           // LCD_ShowString(2, 6, "     ");
        }
    }
}