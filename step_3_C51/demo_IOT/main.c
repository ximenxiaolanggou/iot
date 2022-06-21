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

/*
10								  //固定头				
20                      //代表数据长度
00 06								// 数据协议字节长度
4D 51 49 73 64 70 			// MQIsdp
03									// 版本号 5 
C2									//连接标志
01 2C												//活动时间300s
00 04								//客户端长度 5
74 65 73 74				// 客户端ID用户名对应16进制
00 05                      // 服务器用户名长度5
77 6F 67	75 61			//用户名对应16进制
00 05                      // 服务器密码长度5
77 6F 67	75 61					//服务器密码对应16进制

10 20 00 06 4D 51 49 73 64 70 03 C2 01 2C	00 04 74 65 73 74 00 05 77 6F 67	75 61 00 05 77 6F 67	75 61
10 20 00 06 4D 51 49 73 64 70 03 C2 01 2C 00 04 74 65 73 74 00 05 77 6F 67 75 61 00 05 77 6F 67 75 61
82 15 00 01 00 10 4E 4A 55 53 54 5A 4A 2F 4C 49 53 2F 72 78 30 31 00 // 订阅

C0 00 // 发送心跳

30 1D 00 10 4E 4A 55 53 54 5A 4A 2F 4C 49 53 2F 74 78 30 31 68 65 6C 6C 6F 20 77 6F 6C 64 21 // 发布
*/

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