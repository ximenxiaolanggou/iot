#include <REGX52.H>
#include "LCD1602.h"
#include <REGX52.H>
#include "MATRIX.h"
#include "DELAY.h"
#include "USART.h"



void usart() interrupt 4
{
	if(RI == 1) // �����ж�
	{
		//LED��ʾ
		P2=SBUF;
		//LCD��ʾ
		//LCD_ShowHexNum(1,1,SBUF,2); // ���ͬʱ����LCD��ʾ��Ӱ��LED
		//����������
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