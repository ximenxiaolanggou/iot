#include <REGX52.H>
#include <string.h>
#include <stdio.h>
#include "LCD1602.h"
#include "uart.h"
#include "esp8266.h"
#include "delay.h"
#include "mqtt.h"
#include "timer_0.h"
#include "DS18B20.h"

int index = 0;
int clear = 0;


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
	
	LCD_Init();
	Timer0_Init();
	Uart_Init();
	DS18B20_ConvertT();
	Esp8266_Init_Tcp_Client();
	while(1)
	{
		DS18B20_ConvertT();
		if(CONNECTED_READY)
		{
			P2_0 = 0;
		}
	}

}


void usart() interrupt 4
{
	static char package[20] = ""; //数据包
	static char package_index = 0; // 数据包索引
	static char package_data[10] = ""; //数据包
	static char topic[10] = ""; //topic
	static char topic_package[2] = ""; // topic长度数据包
	static char topic_len = 0; // topic长度
	static char *p;
	static int i;
	if(RI == 1) // 接收中断
	{
		if(SBUF == 0x30){ // MQTT数据报文 - 固定报文
			package[20] = "";
			package_index = 0;
			package[package_index++] = 0x30;
		
		}else if(package_index == 1) { // 剩余数据长度
			P2_2 = !P2_2;
			package[package_index++] = SBUF;
			
		}else if((package[1] + 1) > package_index){
			package[package_index++] = SBUF;
			
		}else if((package[1] + 1) == package_index){ // 数据包采集完成
				P2_3 = !P2_3;
			for(i = 0 ; i < 15 ; i++){
			USART_SendByte(package[i]);
			}
		}
		
		//
		RI = 0;
	
	}
}