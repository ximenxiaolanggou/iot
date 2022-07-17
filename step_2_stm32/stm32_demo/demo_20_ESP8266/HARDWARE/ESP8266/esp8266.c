#include "esp8266.h"
#include "usart2.h"
#include "delay.h"
#include <string.h>

char CONNECTED_READY = 0;
char AT_CWMODE[] = "AT+CWMODE=1\r\n"; // 设置为 softAP+station 共存模式
char AT_RST[] = "AT+RST\r\n"; // 重启生效
char AT_CIPMODE[] = "AT+CIPMODE=1\r\n"; // 开启透传模式
char AT_CIPSEND[] = "AT+CIPSEND\r\n"; // 开始透传发送
char AT_CIPMUX[] = "AT+CIPMUX=0\r\n"; // 单连接
//char AT_CWJAP[] = "AT+CWJAP=\"prinfo-708\",\"prinfo666\"\r\n";
char AT_CWJAP[] = "AT+CWJAP=\"xiaozaizi-4c\",\"qwe369gh147\"\r\n";
char AT_CIPSTART[] = "AT+CIPSTART=\"TCP\",\"150.158.78.149\",1883\r\n";

// 初始化
void ESP8266_Init(){

	USART2_Init();	
	Esp8266_Init_Tcp_Client();
}





// TCP客户端初始化
void Esp8266_Init_Tcp_Client()
{


	USART_SendString(AT_CWMODE);
	delay_ms(1000); // 1s
	
	USART_SendString(AT_RST);
	delay_ms(1000); // 1s

	USART_SendString(AT_CWJAP);
	delay_ms(1000); // 1s
	
	USART_SendString(AT_CIPMUX);
	delay_ms(1000); // 1s
	 
	CONNECTED_READY = 1;

}



