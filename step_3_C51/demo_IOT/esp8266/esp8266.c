#include <REGX52.H>
#include "esp8266.h"
#include "uart.h"
#include "delay.h"


char AT_CIPMUX[] = "AT+CIPMUX=1\r\n";
char AT_CWJAP[] = "AT+CWJAP=\"xiaozaizi-4c\",\"qwe369gh147\"\r\n";
char AT_CIPSTART[] = "AT+CIPSTART=2,\"TCP\",\"192.168.28.154\",11111\r\n";

// ≥ı ºªØ
void Esp8266_Init(void)
{
	USART_SendString(AT_CIPMUX);
	//delay(2000);
	//USART_SendString(AT_CWJAP);
	delay(2000);
	USART_SendString(AT_CIPSTART);
}