#include <string.h>
#include  "mqtt.h"
#include  "sys.h"


// ��¼
void MQTT_Login(char *client_id, char *username, char *password){
	int i;
	//char po[] = {0x10,0x20,0x00,0x06,0x4D,0x51,0x49,0x73,0x64,0x70,0x03,0xC2,0x00,0x3C,0x00,0x04,0x74,0x65,0x73,0x74,0x00,0x05,0x77,0x6F,0x67,0x75,0x61,0x00,0x05,0x77,0x6F,0x67,0x75,0x61};
	int index = 16;
	char fixed_header = 0x10; // �̶�ͷ
	char data_len = 0x12 + strlen(client_id) + strlen(username) + strlen(password);// Э�鳤��
	char protocol[] = {0x00,0x06,0x4D,0x51,0x49,0x73,0x64,0x70}; // Э��汾���� ���ֽ� + Э������ 6�ֽ�
	char version = 0x03; // �汾��
	char connect_tag = 0xC2; // ���ӱ�־
	char active_time[] = {0x00,0x3C}; // �ʱ�� 60s
	
	int len = strlen(client_id);
	char Data[50] = "";
	Data[0] = fixed_header;
	Data[1] = data_len;
	Data[2] = protocol[0];
	Data[3] = protocol[1];
	Data[4] = protocol[2];
	Data[5] = protocol[3];
	Data[6] = protocol[4];
	Data[7] = protocol[5];
	Data[8] = protocol[6];
	Data[9] = protocol[7];
	Data[10] = version;
	Data[11] = connect_tag;
	Data[12] = active_time[0];
	Data[13] = active_time[1];
	Data[14] = 0x00;
	Data[15] = (0x00 + strlen(client_id));
	while(*client_id != '\0')
	{
		Data[index] = *client_id;
		index ++;
		client_id ++;
	}
	
	Data[index++] = 0x00;
	Data[index++] = (0x00 + strlen(username));
	while(*username != '\0')
	{
		Data[index] = *username;
		index ++;
		username ++;
	}
	
	Data[index++] = 0x00;
	Data[index++] = (0x00 + strlen(password));
	while(*password != '\0')
	{
		Data[index] = *password;
		index ++;
		password ++;
	}
	
	for(i = 0 ; i < index ; i ++){
	USART_SendData(USART2,Data[i]);
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//��ȡ����״̬
	}
	
}

// ������
void MQTT_Heart(){

	USART_SendData(USART2,0xC0);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//��ȡ����״̬
	USART_SendData(USART2,0x00);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//��ȡ����״̬

}

/*
82 // �̶�ͷ
09 // ���ݳ��Ȳ������Լ�
00 01 //��Ϣʶ��
00 04 //���ⳤ��
74 65 73 74 //������
00 //Qos
*/
// ��������
void MQTT_Sub(char *topic){
	int i = 0;
	int index = 6;
	char package[50] = "\0";
	char fixed_header = 0x82; // �̶�ͷ
	char data_len = 0x05 + strlen(topic);
	
	
	package[0] = fixed_header;
	package[1] = data_len;
	package[2] = 0x00;
	package[3] = 0x01;
	package[4] = 0x00;
	package[5] = (0x00 + strlen(topic));
	
	while(*topic != '\0')
	{
		package[index++] = *topic;

		topic ++;
	}
	
	package[index++] = 0x00;

	for(i = 0 ; i < index ; i ++){
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//��ȡ����״̬
		USART_SendData(USART2,package[i]);
	}

}

// ����
void MQTT_Pub(char *topic, char *msg) {
	int i = 0;
	int index = 4;
	char package[100] = "\0";
	char fixed_header = 0x30; // �̶�ͷ
	char data_len = 0x02 + strlen(topic) + strlen(msg);
	
	package[0] = fixed_header;
	package[1] = data_len;
	package[2] = 0x00;
	package[3] = (0x00 + strlen(topic));
	
	while(*topic != '\0')
	{
		package[index++] = *topic;
		topic ++;
	}
	
	while(*msg != '\0')
	{
		package[index++] = *msg;
		msg ++;
	}
	
	package[index] = '\0';
	
	for(i = 0 ; i < index ; i ++){
		USART_SendData(USART2,package[i]);
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//��ȡ����״̬
	}
}
	


