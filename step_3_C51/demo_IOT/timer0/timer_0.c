#include <REGX52.H>
#include "timer_0.h"
#include "uart.h"
#include "mqtt.h"
#include "DS18B20.h"
#include <string.h>
#include <stdio.h>
float Temp;
char tBuf[6];
static int num = 0;

char heart[] = {0xC0,0x00};

// 初始化
void Timer0_Init(){
	TMOD |= 0x01; 
	TH0 = 0xfc;
	TL0 = 0x66;
	EA = 1;
	ET0 = 1;
	TR0 = 0;
}



void timer0() interrupt 1
{
	static int count = 0;
	TH0 = 0xfc;
	TL0 = 0x18;
	count++;
	if((count % 10000) == 0){ // 10秒发送一次数据
		Temp = DS18B20_ReadT();
		sprintf(tBuf,"%.2f",Temp);
		MQTT_Pub("temp",tBuf);
		P2_2 = !P2_2;
	
	}
	if(count == 30000) // 30秒一次心跳
	{
		count = 0;
		P2_1 = !P2_1;
		USART_SendByte(heart[0]);
		USART_SendByte(heart[1]);
		num++;
	}
	
	
}