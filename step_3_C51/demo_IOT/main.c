#include <REGX52.H>
#include "uart.h"
#include "esp8266.h"

void main()
{

	Uart_Init();
	Esp8266_Init();
	while(1)
	{
		
	}

}

void usart() interrupt 4
{
	if(RI == 1) // 接收中断
	{
		if(SBUF == 'o') P2_0 = 0;
		if(SBUF == 'k') P2_1 = 0;
		if(SBUF == 'e') P2_3 = 0;
		//LCD_ShowHexNum(1,1,SBUF,2); // 如果同时设置LCD显示会影响LED
		//返还给串口

		RI = 0;
	}	
}