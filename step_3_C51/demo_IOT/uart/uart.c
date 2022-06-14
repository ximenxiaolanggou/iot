#include <REGX52.H>
#include <string.h>
#include "uart.h"
#include "delay.h"

// 初始化
void Uart_Init(void)
{
	SCON = 0x50;
	PCON = 0x80;
	
	TR1 = 1;			//设置定时器 9600 波特率
	TMOD &= 0x0f; 	//设置定时器模式
	TMOD |= 0x20; 	//设置定时器模式
	TL1 = 0xFA;		//设置定时初始值
	TH1 = 0xFA;		//设置定时重载值
	
	EA = 1;
	ES = 1;
	PS = 1;
}

/*
发送数据
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



