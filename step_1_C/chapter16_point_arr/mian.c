#include<stdio.h>

void usart(char SBUF)
{
	static char topic[10] = ""; //topic
	static char DATA[20] = ""; // 数据
	static char DATA_INDEX = 0; // 数据下标
	static char ing = 0; // 是否正在存储
	static char package_len = 0x00; // 数据包长度
	static char topic_len = 0x00; // topic长度
	static char index = 0;
	if(SBUF == 0x30 && ing == 0){ // MQTT接收报文
			DATA[index++] = SBUF;
			ing = 1;
		}
		
		if(ing == 1 && index == 1){ // 报文长度
			package_len = SBUF;
			index ++;
		}
		
		if(ing == 1 && index == 2 && SBUF == 0x00){
			index ++;
		}
		
		if(ing == 1 && index == 3){ // topic长度
			topic_len = SBUF;
			index++;
		}
			
		if(ing == 1 && topic_len != 0x00) { // 收集topic
			topic[index - 4] = SBUF;
			index ++;
			topic_len --;
		}
		
		if(ing == 1 && topic_len == 0x00 && index >= 4 ){ //采集数据
			DATA[DATA_INDEX] = SBUF;
			DATA_INDEX++;
			index++;
			if((package_len + 2) >= index){// 采集结束
				topic[10] = ""; //topic
				DATA[20] = ""; // 数据
				DATA_INDEX = 0; // 数据下标
				ing = 0; // 是否正在存储
				package_len = 0x00; // 数据包长度
				0x00; // topic长度
				index = 0;
			}
		}
	printf("%s\n",topic);
}

int main() {
	char arr[] = {0x30,0x07,0x00,0x04,0x74,0x64,0x73,0x74,0x31};
	int i;
	for(i = 0 ; i < 9 ; i++){
		usart(arr[i]);
	}
	

	return 0;

}