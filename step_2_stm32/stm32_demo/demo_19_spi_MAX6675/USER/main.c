#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "spi1.h"
#include "max6675.h"

	 

 int main(void)
 { 

	 unsigned int t,i;
	unsigned char c;
	unsigned char flag;
	float temprature;
	 
	 MAX6675_Init();
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
 	LCD_Init();	
	 
  while(1) {
		SPI_MAX6675_CS = 0; // 拉低
	    c = MAX6675_ReadByte();
	  printf("test1:%d\r\n",c);
		i = c;
		i = i<<8;
		c = MAX6675_ReadByte();
	  printf("test2:%d\r\n",c);
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
				printf("原始数据是：%04X,  当前温度是：%4.2f。\r\n",i,temprature);
			}	
			else							//热电偶掉线
			{
				printf("未检测到热电偶，请检查。\r\n");
			}
		
		}
		else								//max6675没有数据返回
		{
			printf("max6675没有数据返回，请检查max6675连接。\r\n");
		}
		for(i=0;i<0x2fffff;i++);			//max6675的转换时间是0.2秒左右，所以两次转换间隔不要太近
  }
}
	
