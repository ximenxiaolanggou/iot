#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "usart3.h"
#include "esp8266.h"
#include "string.h"
#include "timer.h"
 
/*
��Ŀ����Ҫ���ݣ�STM32���ESP8266ģ������������ݽ���

ESP8266�����ӣ�USART3��PB10��PB11��

����ж����ݽ�����ȫ��
1�������˻��з���
2���������10ms�˶�û����һ�����ݣ�TIM7������10ms�Ķ�ʱ����
*/


 int main(void)
 {		
	delay_init();	    	 			//��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 			//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 				//���ڳ�ʼ��Ϊ115200
	usart3_init(115200);	 				//���ڳ�ʼ��Ϊ115200

	esp8266_start_trans();							//esp8266���г�ʼ��
	 
	esp8266_send_data("12",50);
	 
	esp8266_quit_trans();

 	while(1)
	{
		
	}
 }

 
 

