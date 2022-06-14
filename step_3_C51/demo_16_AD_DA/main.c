#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "XPT2046.h"

unsigned int ADValue;

int main()
{
	

	LCD_Init();
	LCD_ShowString(1,1,"ADJ  NTC  GR");
	while(1)
	{
		ADValue=XPT2046_ReadAD(XPT2046_XP);		//��ȡAIN0���ɵ�����
		LCD_ShowNum(2,1,ADValue,3);				//��ʾAIN0
		ADValue=XPT2046_ReadAD(XPT2046_YP);		//��ȡAIN1����������
		LCD_ShowNum(2,6,ADValue,3);				//��ʾAIN1
		ADValue=XPT2046_ReadAD(XPT2046_VBAT);	//��ȡAIN2����������
		LCD_ShowNum(2,11,ADValue,3);			//��ʾAIN2
		delay(100);
	}

}