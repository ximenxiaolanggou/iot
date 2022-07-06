#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "dma_adc.h"


 int main(void)
 { 
	
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
	DMA_ADC_Init(8);
	
  	while(1) 
	{		
	
		LCD_ShowString(30,20,200,12,12,"ADC:");
		LCD_ShowxNum(30,40,DMA_ADC_VALUES[0],4,12,0);
		LCD_ShowxNum(30,60,DMA_ADC_VALUES[1],4,12,0);
		LCD_ShowxNum(30,80,DMA_ADC_VALUES[2],4,12,0);
		LCD_ShowxNum(30,100,DMA_ADC_VALUES[3],4,12,0);
		LCD_ShowxNum(30,120,DMA_ADC_VALUES[4],4,12,0);
		LCD_ShowxNum(30,140,DMA_ADC_VALUES[5],4,12,0);
		LCD_ShowxNum(30,160,DMA_ADC_VALUES[6],4,12,0);
		LCD_ShowxNum(30,180,DMA_ADC_VALUES[7],4,12,0);
		
		delay_ms(100);
		

	} 
	
}
