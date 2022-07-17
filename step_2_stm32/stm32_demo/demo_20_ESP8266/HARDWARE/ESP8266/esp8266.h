#ifndef __ESP8266_H
#define __ESP8266_H	 
#include "sys.h"

extern char CONNECTED_READY;
extern char AT_CWMODE[]; // ����Ϊ softAP+station ����ģʽ
extern char AT_RST[]; // ������Ч
extern char AT_CIPMODE[]; // ����͸��ģʽ
extern char AT_CIPSEND[]; // ��ʼ͸������
extern char AT_CIPMUX[]; // ������
//char AT_CWJAP[] = "AT+CWJAP=\"prinfo-708\",\"prinfo666\"\r\n";
extern char AT_CWJAP[];
extern char AT_CIPSTART[];



// ��ʼ��
void ESP8266_Init(void);

// TCP�ͻ��˳�ʼ��
void Esp8266_Init_Tcp_Client(void);

		 				    
#endif
