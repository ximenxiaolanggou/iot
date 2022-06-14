#include <REGX52.H>
#include <string.h>
#include "uart.h"
#include "delay.h"

// ��ʼ��
void Uart_Init(void)
{
	SCON = 0x50;
	PCON = 0x80;
	
	TR1 = 1;			//���ö�ʱ�� 9600 ������
	TMOD &= 0x0f; 	//���ö�ʱ��ģʽ
	TMOD |= 0x20; 	//���ö�ʱ��ģʽ
	TL1 = 0xFA;		//���ö�ʱ��ʼֵ
	TH1 = 0xFA;		//���ö�ʱ����ֵ
	
	EA = 1;
	ES = 1;
	PS = 1;
}

/*
��������
*/
void USART_SendByte(unsigned char byteData)
{
	SBUF = byteData;
	while(TI == 0);
	TI = 0;
}

void USART_SendString(char *strData)
{
	while(*strData != '\0')
	{
		USART_SendByte(*strData);
		strData++;
	}
	
}



