#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct
{
	unsigned char a:2;
	unsigned char :4; // 无意义的段位 占4位
	unsigned char b:2;

}DATA;

typedef struct
{
	unsigned char a:2;
	unsigned char 0; // 另起一个位段
	unsigned char b:2;

}DATA;

int main() {
	DATA b;
	memset(&b,0,sizeof(b));
	b.a = 3;
	b.b = 0;
	printf("sizeof:%d\n",sizeof(b));
	printf("%#x\n",b);

}