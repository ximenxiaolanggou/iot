#include <REGX52.H>
#include <USART.H>

/*
初始化
*/
void USART_Init()
{
	SCON = 0x50;
	PCON |= 0x80;
	
	TR1 = 1;
	TMOD &= 0x0f; //设置定时器模式
	TMOD |= 0x20; //设置定时器模式
	TL1 = 0xF4;		//设置定时初始值
	TH1 = 0xF4;		//设置定时重载值
	EA = 1;
	ES = 1;
	
}

/*
发送数据
*/
void USART_Send(unsigned char byteData)
{
	SBUF = byteData;
	while(TI == 0);
	TI = 0;
}