#include <REGX52.H>
#include "uart.h"
#include "esp8266.h"
#include "delay.h"
#include "LCD1602.h"
#include <string.h>
#include <INTRINS.H>

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
		if(CONNECTED_READY)
		{
			P2_0 = 0;
			USART_SendString("test123");
			delay_ns(1);
		}
	}

}

void usart() interrupt 4
{
	
	if(RI == 1)// 接收中断
	{
		if(SBUF == '\r'){  // 接收结束标志位
			clear = 1;
		}else{
			str[index] = SBUF;
			index++;
		}
		
		if(clear == 1){ // 数据接收完成
			if(strstr(str, "CONNECTEDWIFI") != NULL){ // wifi链接成功，TCP客户端链接服务端
				P2_0 = 0;
				P2_1 = 0;
				//Esp8266_CIPMUX(); // 设置多连接
				//Esp8266_TCP_CLIENT_CONNECT(); // TCP连接
			}
			str[32] = "";
			index = 0;
			clear = 0;
		
		}
		RI = 0;
	
	}
}