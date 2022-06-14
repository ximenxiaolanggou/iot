#include <REGX52.H>
#include "LCD1602.h"
#include <REGX52.H>
#include "MATRIX.h"
#include "DELAY.h"
#include "USART.h"



void usart() interrupt 4
{
	if(RI == 1) // 接收中断
	{
		//LED显示
		P2=SBUF;
		//LCD显示
		//LCD_ShowHexNum(1,1,SBUF,2); // 如果同时设置LCD显示会影响LED
		//返还给串口
		USART_Send(SBUF);
		RI = 0;
	}
	
	
	
}

int main()
{
	LCD_Init();
	USART_Init();
	P2 = 0xaa;
	while(1)
	{

	}
}