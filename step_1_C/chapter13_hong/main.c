#include<stdio.h>

#define A 10

#define B(a,b) a*b

#define C(a,b) (a)*(b)


int main() {

	printf("%d\n",A);

	printf("%d\n",B(10+10,20+20));

	printf("%d\n",C(10+10,20+20));

// δ�����
#ifdef D
	printf("����D\n");
#else
	printf("δ����D\n");
#endif

// �����
#ifndef D
	printf("δ����D\n");
#else
	printf("����D\n");
#endif

	// �����ж�
#if 0
	printf("0\n");
#else
	printf("1\n");
#endif


return 0;

}