#include<stdio.h>

int main() {

	char buf[5] = "";

	//scanf("%s", &buf); // �������ݲ��ܴ��ڿո�

	//gets(buf); // ���������ݳ���buf��������С����������ڴ�������Ⱦ
	
	fgets(&buf, sizeof(buf),stdin);

	printf("%s\n",buf);
}