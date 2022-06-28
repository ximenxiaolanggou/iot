#include<stdio.h>

void usart(char SBUF)
{
	static char topic[10] = ""; //topic
	static char DATA[20] = ""; // ����
	static char DATA_INDEX = 0; // �����±�
	static char ing = 0; // �Ƿ����ڴ洢
	static char package_len = 0x00; // ���ݰ�����
	static char topic_len = 0x00; // topic����
	static char index = 0;
	if(SBUF == 0x30 && ing == 0){ // MQTT���ձ���
			DATA[index++] = SBUF;
			ing = 1;
		}
		
		if(ing == 1 && index == 1){ // ���ĳ���
			package_len = SBUF;
			index ++;
		}
		
		if(ing == 1 && index == 2 && SBUF == 0x00){
			index ++;
		}
		
		if(ing == 1 && index == 3){ // topic����
			topic_len = SBUF;
			index++;
		}
			
		if(ing == 1 && topic_len != 0x00) { // �ռ�topic
			topic[index - 4] = SBUF;
			index ++;
			topic_len --;
		}
		
		if(ing == 1 && topic_len == 0x00 && index >= 4 ){ //�ɼ�����
			DATA[DATA_INDEX] = SBUF;
			DATA_INDEX++;
			index++;
			if((package_len + 2) >= index){// �ɼ�����
				topic[10] = ""; //topic
				DATA[20] = ""; // ����
				DATA_INDEX = 0; // �����±�
				ing = 0; // �Ƿ����ڴ洢
				package_len = 0x00; // ���ݰ�����
				0x00; // topic����
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