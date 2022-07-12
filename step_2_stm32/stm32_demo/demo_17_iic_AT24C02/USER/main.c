#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "at24c02.h"

u8 Data = 0;
u8 Data_Address = 0;

 int main(void)
 { 
	
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
	AT24C02_Init();
  while(1) 
	{		
	  AT24C02_SendByte(Data_Address % 100,Data_Address % 100);
	  Data = AT24C02_ReadByte(Data_Address % 100);
		LCD_ShowString(30,20,200,12,24,"EPPROM:");
		LCD_ShowNum(30,60,Data,3,12);
		Data ++;
		Data_Address ++;
		delay_ms(1000);
	}
	
}
