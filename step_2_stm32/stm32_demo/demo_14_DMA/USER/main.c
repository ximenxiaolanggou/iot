#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "mydma.h"

uint8_t DataA[] = {0x01,0x02,0x03,0x04};
uint8_t DataB[] = {0,0,0,0};

 int main(void)
 { 
	
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
	MYDMA_Init((uint32_t)DataA,(uint32_t)DataB,4);
	
  	while(1) 
	{		
		MYDMA_Transfer();		
		printf("%d\r\n",DataB[0]);
		printf("%d\r\n",DataB[1]);
		printf("%d\r\n",DataB[2]);
		printf("%d\r\n",DataB[3]);
		printf("end~~\r\n");
		delay_ms(1000);
		DataA[0]++;
		DataA[1]++;
		DataA[2]++;
		DataA[3]++;
	} 
	
}
