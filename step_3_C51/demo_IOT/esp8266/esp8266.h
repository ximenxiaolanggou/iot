#ifndef __ESP8266_H__
#define __ESP8266_H__

extern char CONNECTED_READY;
char AT_CIPMUX[];
char AT_CWJAP[];
char AT_CIPSTART[];


// TCP�ͻ��˳�ʼ��
void Esp8266_Init_Tcp_Client(void);

// TCP�ͻ�������
void Esp8266_TCP_CLIENT_CONNECT(void);

// ������
void Esp8266_CIPMUX(void);

// ��������
void Esp8266_SendData(char *Data);

// ��������
void MQTT_Sub(char *topic);
#endif