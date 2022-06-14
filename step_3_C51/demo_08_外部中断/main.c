#include <REGX52.H>
#include "LCD1602.h"
#include <REGX52.H>
#include "MATRIX.h"
#include "DELAY.h"

/*

外部中断控制LED
*/

void EX0_Init()
{
	EA = 1;
	EX0 = 1;
	IT0 = 0;
}

void ex0() interrupt 0
{
	P2_0 = !P2_0;
	delay(10);
	while(!P3_2);
	delay(10);
}

int main()
{
	EX0_Init();
	while(1)
	{
		
	}
}