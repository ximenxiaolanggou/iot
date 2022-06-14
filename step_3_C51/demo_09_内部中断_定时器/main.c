#include <REGX52.H>
#include "LCD1602.h"
#include <REGX52.H>
#include "MATRIX.h"
#include "DELAY.h"

/*

内部中断定时器，每个一秒LCD加1
*/

static int num = 0;

void timer0_Init()
{
	TMOD |= 0x01; 
	TH0 = 0xfc;
	TL0 = 0x18;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	
}

void timer0() interrupt 1
{
	static int count = 0;
	TH0 = 0xfc;
	TL0 = 0x18;
	count++;
	if(count == 1000)
	{
		count = 0;
		P2_0 = !P2_0;
		num++;
	}
	
}

int main()
{
	LCD_Init();
	timer0_Init();
	while(1)
	{
		LCD_ShowNum(1,1,num,2);
	}
}