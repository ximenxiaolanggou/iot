#include <string.h>
#include  "mqtt.h"
#include  "sys.h"


// 登录
void MQTT_Login(char *client_id, char *username, char *password){
	int i;
	//char po[] = {0x10,0x20,0x00,0x06,0x4D,0x51,0x49,0x73,0x64,0x70,0x03,0xC2,0x00,0x3C,0x00,0x04,0x74,0x65,0x73,0x74,0x00,0x05,0x77,0x6F,0x67,0x75,0x61,0x00,0x05,0x77,0x6F,0x67,0x75,0x61};
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
	USART_SendData(USART2,Data[i]);
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//读取串口状态
	}
	
}

// 心跳包
void MQTT_Heart(){

	USART_SendData(USART2,0xC0);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//读取串口状态
	USART_SendData(USART2,0x00);
	while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//读取串口状态

}

/*
82 // 固定头
09 // 数据长度不包含自己
00 01 //消息识别
00 04 //主题长度
74 65 73 74 //主题名
00 //Qos
*/
// 订阅主题
void MQTT_Sub(char *topic){
	int i = 0;
	int index = 6;
	char package[50] = "\0";
	char fixed_header = 0x82; // 固定头
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
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//读取串口状态
		USART_SendData(USART2,package[i]);
	}

}

// 发布
void MQTT_Pub(char *topic, char *msg) {
	int i = 0;
	int index = 4;
	char package[100] = "\0";
	char fixed_header = 0x30; // 固定头
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
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//读取串口状态
	}
}
	


