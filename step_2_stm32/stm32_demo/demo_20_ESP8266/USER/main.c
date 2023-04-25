#include "led.h"
#include "delay.h"
#include "sys.h"
#include "esp8266.h"
#include "key.h"
#include "exti.h"
#include "usart2.h"
#include "timer.h"
#include "spi1.h"
#include "max6675.h"

 int main(void)
 { 
	  unsigned int t,i;
	unsigned char c;
	unsigned char flag;
	float temprature;
	 char tempratureArr[7] ="";
	 
	
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 LED_Init();
	 delay_init();
	 KEY_Init();
	 ESP8266_Init();
	 EXTIX_Init();
	  MAX6675_Init();
	 TIMER_3_Init(9999,7199); // 1000ms
	while(1) {
		SPI_MAX6675_CS = 0; // 拉低
		
	    c = MAX6675_ReadByte();
		i = c;
		i = i<<8;
		c = MAX6675_ReadByte();
		SPI_MAX6675_CS = 1; // 拉高
		
		i = i|((unsigned int)c);			//i是读出来的原始数据
		flag = i&0x04;						//flag保存了热电偶的连接状态
		t = i<<1;
		t = t>>4;
		temprature = t*0.25;
		if(i!=0)							//max6675有数据返回
		{
			if(flag==0)						//热电偶已连接
			{
				USART_SendString("原始数据是：\r\n");
				tempratureArr[0] = (char) temprature;
				tempratureArr[1] = (char) temprature >> 8;
				tempratureArr[2] = (char) temprature >> 16;
				tempratureArr[3] = (char) temprature >> 24;
	
				USART_SendString(tempratureArr);
				
			}	
			else							//热电偶掉线
			{
				USART_SendString("未检测到热电偶，请检查。\r\n");
			}
		
		}
		else								//max6675没有数据返回
		{
			
			USART_SendString("max6675没有数据返回，请检查max6675连接。\r\n");
		}
		delay_ms(1000);
  }
}
 

