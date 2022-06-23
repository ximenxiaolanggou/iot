#include <REGX52.H>
#include "esp8266.h"
#include "uart.h"
#include "delay.h"
#include "mqtt.h"
#include <string.h>
#include <INTRINS.H>
char CONNECTED_READY = 0;
char AT_CWMODE[] = "AT+CWMODE=3\r\n"; // ����Ϊ softAP+station ����ģʽ
char AT_RST[] = "AT+RST\r\n"; // ������Ч
char AT_CIPMODE[] = "AT+CIPMODE=1\r\n"; // ����͸��ģʽ
char AT_CIPSEND[] = "AT+CIPSEND\r\n"; // ��ʼ͸������
char AT_CIPMUX[] = "AT+CIPMUX=0\r\n"; // ������
//char AT_CWJAP[] = "AT+CWJAP=\"prinfo-708\",\"prinfo666\"\r\n";
char AT_CWJAP[] = "AT+CWJAP=\"prinfo-708\",\"prinfo666\"\r\n";
char AT_CIPSTART[] = "AT+CIPSTART=\"TCP\",\"150.158.78.149\",1883\r\n";


// TCP�ͻ��˳�ʼ��
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
	
	
	
	USART_SendString(AT_CIPSTART);
	delay_ns(6); // 6000ms
	
	USART_SendString(AT_CIPMODE);
	delay_ns(2); // 2000ms
	
	USART_SendString(AT_CIPSEND);
	delay_ns(2); // 2000ms
	MQTT_Login("test","wogua","wogua");
	delay_ns(2); // 2000ms
	TR0 = 1;// ������ʱ��0 ����������
	delay_ns(1); // 1000ms
	MQTT_Sub("test");
	delay_ns(1); // 1000ms
	CONNECTED_READY = 1;

}

// TCP�ͻ�������
void Esp8266_TCP_CLIENT_CONNECT(void)
{
	USART_SendString(AT_CIPSTART);
	delay(10);
}

// ������
void Esp8266_CIPMUX(void)
{
	USART_SendString(AT_CIPMUX);
	delay(10);
}


// �������� ���ݱ�$$����
void Esp8266_SendData(char *Data){
	char *AtData = "AT+CIPSEND=$";
	strcat(AtData,Data);
	strcat(AtData,"$");
	USART_SendString(AtData);
}