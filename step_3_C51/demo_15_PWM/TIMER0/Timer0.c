#include <REGX52.H>
#include "Timer0.H"

unsigned char CountNum = 0;

unsigned char CompareNum = 0;

// 初始化
void Timer0_Init(void)
{
	TMOD |= 0x01; 
	TL0 = 0x9C;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

// 定时函数
void timer0() interrupt 1
{
	
	CountNum ++;
	CountNum = CountNum%100;
	TL0 = 0x9C;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	
	if(CountNum < CompareNum)
		{
			P2_0 = 0;
		}else {
			P2_0 = 1;
		}
	
}

// 设置比较值
void SetCompareNum(unsigned char num)
{
	CompareNum = num;
}