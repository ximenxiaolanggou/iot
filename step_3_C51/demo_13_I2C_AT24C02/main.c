#include <REGX52.H>
#include "LCD1602.h"
#include "MATRIX.h"
#include "DELAY.h"
#include "DS1302.h"
#include "AT24C02.H"

unsigned char Data;

int main()
{
	LCD_Init();
	AT24C02_WriteByte(0,12);
	delay(50);
	Data = AT24C02_ReadByte(0);
	LCD_ShowNum(1,1,Data,3);
	while(1)
	{
	

	}
}