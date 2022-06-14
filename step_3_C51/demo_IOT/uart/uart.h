#ifndef __UART_H__
#define __UART_H__

// 初始化
void Uart_Init(void);

// 发送数据
void USART_SendByte(unsigned char byteData);

void USART_SendString(char *strData);
#endif