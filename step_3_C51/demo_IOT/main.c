#include <REGX52.H>


#include "uart.h"
#include "esp8266.h"
#include "delay.h"
#include "LCD1602.h"
#include<string.h>

int index = 0;
int clear = 0;
char str[32] = "";

void main()
{
	Uart_Init();
	LCD_Init();
	Esp8266_Init_Tcp_Client();
	while(1)
	{
		while(P3_3 == 0)
		{
			delay(10);
			while(P3_3 == 0);
			Esp8266_CIPMUX(); // ���ö�����
			delay(10);
			USART_SendString(AT_CIPSTART);
			delay(10);
		}
	}

}

void usart() interrupt 4
{
	
	if(RI == 1)// �����ж�
	{
		if(SBUF == '\r'){  // ���ս�����־λ
			clear = 1;
		}else{
			str[index] = SBUF;
			index++;
		}
		
		if(clear == 1){ // ���ݽ������
			if(strstr(str, "CONNECTEDWIFI") != NULL){ // wifi���ӳɹ���TCP�ͻ������ӷ����
				P2_0 = 0;
				P2_1 = 0;
				//Esp8266_CIPMUX(); // ���ö�����
				//Esp8266_TCP_CLIENT_CONNECT(); // TCP����
			}
			str[32] = "";
			index = 0;
			clear = 0;
		
		}
		RI = 0;
	
	}
}