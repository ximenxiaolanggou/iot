#ifndef __ESP8266_H
#define __ESP8266_H	 
#include "sys.h"

extern char CONNECTED_READY;
extern char AT_CWMODE[]; // 设置为 softAP+station 共存模式
extern char AT_RST[]; // 重启生效
extern char AT_CIPMODE[]; // 开启透传模式
extern char AT_CIPSEND[]; // 开始透传发送
extern char AT_CIPMUX[]; // 单连接
//char AT_CWJAP[] = "AT+CWJAP=\"prinfo-708\",\"prinfo666\"\r\n";
extern char AT_CWJAP[];
extern char AT_CIPSTART[];



// 初始化
void ESP8266_Init(void);

// TCP客户端初始化
void Esp8266_Init_Tcp_Client(void);

		 				    
#endif
