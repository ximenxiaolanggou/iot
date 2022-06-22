#ifndef __ESP8266_H__
#define __ESP8266_H__

extern char CONNECTED_READY;
char AT_CIPMUX[];
char AT_CWJAP[];
char AT_CIPSTART[];


// TCP客户端初始化
void Esp8266_Init_Tcp_Client(void);

// TCP客户端链接
void Esp8266_TCP_CLIENT_CONNECT(void);

// 多连接
void Esp8266_CIPMUX(void);

// 发送数据
void Esp8266_SendData(char *Data);

// 订阅主题
void MQTT_Sub(char *topic);
#endif