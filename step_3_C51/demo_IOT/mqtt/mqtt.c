#include <string.h>
#include  "mqtt.h"
#include  "uart.h"


// 登录
void MQTT_Login(char *client_id, char *username, char *password){
	int i;
	//char po[] = {0x10,0x20,0x00,0x06,0x4D,0x51,0x49,0x73,0x64,0x70,0x03,0xC2,0x01,0x2C,0x00,0x04,0x74,0x65,0x73,0x74,0x00,0x05,0x77,0x6F,0x67,0x75,0x61,0x00,0x05,0x77,0x6F,0x67,0x75,0x61};
	int index = 16;
	char fixed_header = 0x10; // 固定头
	char data_len = 0x12 + strlen(client_id) + strlen(username) + strlen(password);// 协议长度
	char protocol[] = {0x00,0x06,0x4D,0x51,0x49,0x73,0x64,0x70}; // 协议版本长度 两字节 + 协议名称 6字节
	char version = 0x03; // 版本号
	char connect_tag = 0xC2; // 连接标志
	char active_time[] = {0x00,0x3C}; // 活动时长 60s
	
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
	USART_SendByte(Data[i]);
	}
	
}
	


