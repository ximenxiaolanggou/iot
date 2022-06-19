#include <REGX52.H>
#include "esp8266.h"
#include "uart.h"
#include "delay.h"
#include <string.h>
#include "LCD1602.h"
#include <INTRINS.H>
char CONNECTED_READY = 0;
char AT_CWMODE[] = "AT+CWMODE=3\r\n"; // 设置为 softAP+station 共存模式
char AT_RST[] = "AT+RST\r\n"; // 重启生效
char AT_CIPMODE[] = "AT+CIPMODE=1\r\n"; // 开启透传模式
char AT_CIPSEND[] = "AT+CIPSEND\r\n"; // 开始透传发送
char AT_CIPMUX[] = "AT+CIPMUX=0\r\n"; // 单连接
char AT_CWJAP[] = "AT+CWJAP=\"xiaozaizi-4c\",\"qwe369gh147\"\r\n";
char AT_CIPSTART[] = "AT+CIPSTART=\"TCP\",\"192.168.28.154\",11111\r\n";


// TCP客户端初始化
void Esp8266_Init_Tcp_Client(void)
{

	USART_SendString(AT_CWMODE);
	delay_ns(1); // 1s
	
	USART_SendString(AT_RST);
	delay_ns(1); // 1s
	
	USART_SendString(AT_CWJAP);
	delay_ns(6); // 6000ms
	
	USART_SendString(AT_CIPMUX);
	delay_ns(1); // 1000ms
	
	USART_SendString(AT_CIPMODE);
	delay_ns(2); // 2000ms
	
	USART_SendString(AT_CIPSTART);
	delay_ns(6); // 6000ms
	
	USART_SendString(AT_CIPSEND);
	delay_ns(2); // 2000ms
	
	CONNECTED_READY = 1;

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