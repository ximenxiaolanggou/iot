#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "tsensor.h"

//ALIENTEK Mini STM32开发板范例代码11
//TFTLCD显示实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司 
 int main(void)
 { 
	u16 adV=0;					// AD值
	double vV = 0.0;		// 电压值
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
	TSENSOR_Init();	
	LCD_ShowString(10,70,200,16,16,"00.00");	 
  	while(1) 
	{		 
		adV = AD_Tsensor_GetValue_Avg(ADC_Channel_16, 10);
		LCD_ShowxNum(10,40,adV,4,24,0);
		
		vV = (float)adV * (3.3 / 4096);

		vV = (1.43 - vV)/0.0043 + 25 ;
		
		adV = vV;
		LCD_ShowxNum(10,70,adV,2,16,0);
		
		vV -= adV;
		vV *= 1000;
		LCD_ShowxNum(10 + 3*8,70,vV,2,16,0);
	} 
}
