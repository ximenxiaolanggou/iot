#include <REGX52.H>
#include "esp8266.h"
#include "uart.h"
#include "delay.h"
#include <string.h>


char AT_CIPMUX[] = "AT+CIPMUX=1\r\n";
char AT_CWJAP[] = "AT+CWJAP=\"prinfo-708\",\"prinfo666\"\r\n";
char AT_CIPSTART[] = "AT+CIPSTART=1,\"TCP\",\"192.168.2.31\",11111\r\n";

// TCP客户端初始化
void Esp8266_Init_Tcp_Client(void)
{

	USART_SendString(AT_CIPMUX);
	delay(100); // 100ms
	USART_SendString(AT_CIPSTART);
	delay(100); // 100ms
}

// 8266 发送命令
void Esp8266_Send_Command(char *cmd,char ack,int waittime)
{

}

// TCP客户端链接
void Esp8266_TCP_CLIENT_CONNECT(void)
{
	USART_SendString(AT_CIPSTART);
	delay(10);
}

// 多连接
void Esp8266_CIPMUX(void)
{
	USART_SendString(AT_CIPMUX);
	delay(10);
}


// 发送数据 数据被$$包含
void Esp8266_SendData(char *Data){
	char *AtData = "AT+CIPSEND=$";
	strcat(AtData,Data);
	strcat(AtData,"$");
	USART_SendString(AtData);
}