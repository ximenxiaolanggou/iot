#include <REGX52.H>
#include "LCD1602.h"
#include <REGX52.H>
#include "MATRIX.h"
int main()
{
	unsigned char pressKey;
	LCD_Init();
	while(1)
	{
		pressKey = getPressKey();
		LCD_ShowNum(1,1,pressKey,2);
	}
}