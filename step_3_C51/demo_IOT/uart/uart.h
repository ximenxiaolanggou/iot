#ifndef __UART_H__
#define __UART_H__

// ��ʼ��
void Uart_Init(void);

// ��������
void USART_SendByte(unsigned char byteData);

void USART_SendString(char *strData);
#endif