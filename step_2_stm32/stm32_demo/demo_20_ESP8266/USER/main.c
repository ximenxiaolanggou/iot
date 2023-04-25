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
		SPI_MAX6675_CS = 0; // ����
		
	    c = MAX6675_ReadByte();
		i = c;
		i = i<<8;
		c = MAX6675_ReadByte();
		SPI_MAX6675_CS = 1; // ����
		
		i = i|((unsigned int)c);			//i�Ƕ�������ԭʼ����
		flag = i&0x04;						//flag�������ȵ�ż������״̬
		t = i<<1;
		t = t>>4;
		temprature = t*0.25;
		if(i!=0)							//max6675�����ݷ���
		{
			if(flag==0)						//�ȵ�ż������
			{
				USART_SendString("ԭʼ�����ǣ�\r\n");
				tempratureArr[0] = (char) temprature;
				tempratureArr[1] = (char) temprature >> 8;
				tempratureArr[2] = (char) temprature >> 16;
				tempratureArr[3] = (char) temprature >> 24;
	
				USART_SendString(tempratureArr);
				
			}	
			else							//�ȵ�ż����
			{
				USART_SendString("δ��⵽�ȵ�ż�����顣\r\n");
			}
		
		}
		else								//max6675û�����ݷ���
		{
			
			USART_SendString("max6675û�����ݷ��أ�����max6675���ӡ�\r\n");
		}
		delay_ms(1000);
  }
}
 

