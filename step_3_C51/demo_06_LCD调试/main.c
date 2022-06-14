#include <REGX52.H>
#include "LCD1602.h"
int main()
{
	LCD_Init();
	while(1)
	{
		LCD_ShowChar(1,1,'A');
	}
}