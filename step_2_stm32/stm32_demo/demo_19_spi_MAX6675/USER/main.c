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
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
 	LCD_Init();	
	 
  while(1) {
		SPI_MAX6675_CS = 0; // ����
	    c = MAX6675_ReadByte();
	  printf("test1:%d\r\n",c);
		i = c;
		i = i<<8;
		c = MAX6675_ReadByte();
	  printf("test2:%d\r\n",c);
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
				printf("ԭʼ�����ǣ�%04X,  ��ǰ�¶��ǣ�%4.2f��\r\n",i,temprature);
			}	
			else							//�ȵ�ż����
			{
				printf("δ��⵽�ȵ�ż�����顣\r\n");
			}
		
		}
		else								//max6675û�����ݷ���
		{
			printf("max6675û�����ݷ��أ�����max6675���ӡ�\r\n");
		}
		for(i=0;i<0x2fffff;i++);			//max6675��ת��ʱ����0.2�����ң���������ת�������Ҫ̫��
  }
}
	
