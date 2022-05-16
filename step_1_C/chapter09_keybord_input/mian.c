#include<stdio.h>

int main() {

	char buf[5] = "";

	//scanf("%s", &buf); // 输入内容不能存在空格

	//gets(buf); // 当输入内容超过buf缓冲区大小会造成其他内存数据污染
	
	fgets(&buf, sizeof(buf),stdin);

	printf("%s\n",buf);
}