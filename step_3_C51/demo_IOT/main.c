#include <REGX52.H>
#include <string.h>
#include <stdio.h>
#include "LCD1602.h"
#include "uart.h"
#include "esp8266.h"
#include "delay.h"
#include "mqtt.h"
#include "timer_0.h"
#include "DS18B20.h"

int index = 0;
int clear = 0;


/*
10								  //�̶�ͷ				
20                      //�������ݳ���
00 06								// ����Э���ֽڳ���
4D 51 49 73 64 70 			// MQIsdp
03									// �汾�� 5 
C2									//���ӱ�־
01 2C												//�ʱ��300s
00 04								//�ͻ��˳��� 5
74 65 73 74				// �ͻ���ID�û�����Ӧ16����
00 05                      // �������û�������5
77 6F 67	75 61			//�û�����Ӧ16����
00 05                      // ���������볤��5
77 6F 67	75 61					//�����������Ӧ16����

10 20 00 06 4D 51 49 73 64 70 03 C2 01 2C	00 04 74 65 73 74 00 05 77 6F 67	75 61 00 05 77 6F 67	75 61
10 20 00 06 4D 51 49 73 64 70 03 C2 01 2C 00 04 74 65 73 74 00 05 77 6F 67 75 61 00 05 77 6F 67 75 61
82 15 00 01 00 10 4E 4A 55 53 54 5A 4A 2F 4C 49 53 2F 72 78 30 31 00 // ����

C0 00 // ��������

30 1D 00 10 4E 4A 55 53 54 5A 4A 2F 4C 49 53 2F 74 78 30 31 68 65 6C 6C 6F 20 77 6F 6C 64 21 // ����
*/

void main()
{
	
	LCD_Init();
	Timer0_Init();
	Uart_Init();
	DS18B20_ConvertT();
	Esp8266_Init_Tcp_Client();
	while(1)
	{
		DS18B20_ConvertT();
		if(CONNECTED_READY)
		{
			P2_0 = 0;
		}
	}

}


void usart() interrupt 4
{

	if(RI == 1)// �����ж�
	{
	
		RI = 0;
	
	}
}