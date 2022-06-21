#include <REGX52.H>
#include "uart.h"
#include "esp8266.h"
#include "delay.h"
#include "LCD1602.h"
#include <string.h>
#include <INTRINS.H>

int index = 0;
int clear = 0;
char str[32] = "";

/*
10								  //�̶�ͷ				
24                       //�������ݳ���
00 04								// ����Э���ֽڳ���
4D 51 54 54 			// MQIsdp
05									// �汾�� 5 
C2									//���ӱ�־
01 2C												//�ʱ��300s
00 04								//�ͻ��˳��� 5
74 65 73 74				// �ͻ���ID�û�����Ӧ16����
00 08                      // �������û�������5
64 61 6D 6F 6E	63 61 69				//�û�����Ӧ16����
00 08                      // ���������볤��5
64 61 6D 6F 6E	63 61 69					//�����������Ӧ16����

10 24 00 06 4D 51 54 54 05 C2	01 2C 00 04 74 65 73 74 00 08 64 61 6D 6F 6E	63 61 69 00 08 64 61 6D 6F 6E	63 61 69

82 15 00 01 00 10 4E 4A 55 53 54 5A 4A 2F 4C 49 53 2F 72 78 30 31 00 // ����

C0 00 // ��������

30 1D 00 10 4E 4A 55 53 54 5A 4A 2F 4C 49 53 2F 74 78 30 31 68 65 6C 6C 6F 20 77 6F 6C 64 21 // ����
*/

void main()
{
	Uart_Init();
	LCD_Init();
	Esp8266_Init_Tcp_Client();
	while(1)
	{
		if(CONNECTED_READY)
		{
			P2_0 = 0;
			USART_SendString("test123");
			delay_ns(1);
		}
	}

}

void usart() interrupt 4
{
	
	if(RI == 1)// �����ж�
	{
		if(SBUF == '\r'){  // ���ս�����־λ
			clear = 1;
		}else{
			str[index] = SBUF;
			index++;
		}
		
		if(clear == 1){ // ���ݽ������
			if(strstr(str, "CONNECTEDWIFI") != NULL){ // wifi���ӳɹ���TCP�ͻ������ӷ����
				P2_0 = 0;
				P2_1 = 0;
				//Esp8266_CIPMUX(); // ���ö�����
				//Esp8266_TCP_CLIENT_CONNECT(); // TCP����
			}
			str[32] = "";
			index = 0;
			clear = 0;
		
		}
		RI = 0;
	
	}
}