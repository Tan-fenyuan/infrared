#ifndef __UART_H__
#define __UART_H__

#include <REGX52.H>

void UART_Init();
char UART_GetBuff();
void URAT_SendByte(unsigned char Byte);
#endif