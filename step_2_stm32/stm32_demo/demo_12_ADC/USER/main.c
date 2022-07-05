#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "adc.h"

//ALIENTEK Mini STM32�����巶������11
//TFTLCD��ʾʵ��   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾ 
 int main(void)
 { 
	u16 adV=0;					// ADֵ
	float vV = 0.0f;		// ��ѹֵ
	u8 lcd_id[12];			//���LCD ID�ַ���	
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
 	LCD_Init();
	Adc_Init();	
	LCD_ShowString(10,70,200,24,24,"0.00");	 
  	while(1) 
	{		 
		adV = AD_GetValue_Avg(ADC_Channel_0, 10);
		LCD_ShowxNum(10,40,adV,4,24,0);
		
		vV = (float)adV * (3.3 / 4096); 
		
		adV = vV;
		LCD_ShowxNum(10,70,adV,1,24,0);
		
		vV -= adV;
		vV *= 1000;
		LCD_ShowxNum(26,70,vV,3,24,0);
	} 
}
