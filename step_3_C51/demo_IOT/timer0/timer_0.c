#include <REGX52.H>
#include <string.h>
#include <stdio.h>
#include "LCD1602.h"
#include "timer_0.h"
#include "uart.h"
#include "mqtt.h"
#include "DS18B20.h"



char COLLECT[2];

// ��ʼ��
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
	TL0 = 0x66;
	count++;
	
	if(count == 30000) // 30��һ������
	{
		count = 0;
		P2_1 = !P2_1;
		MQTT_Heart();// ��������
		DS18B20_ReadT(COLLECT); // �����¶�����
		MQTT_Pub("temp",COLLECT);
	}	
}