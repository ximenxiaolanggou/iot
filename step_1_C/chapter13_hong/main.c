#include<stdio.h>

#define A 10

#define B(a,b) a*b

#define C(a,b) (a)*(b)


int main() {

	printf("%d\n",A);

	printf("%d\n",B(10+10,20+20));

	printf("%d\n",C(10+10,20+20));

// 未定义宏
#ifdef D
	printf("定义D\n");
#else
	printf("未定义D\n");
#endif

// 定义宏
#ifndef D
	printf("未定义D\n");
#else
	printf("定义D\n");
#endif

	// 条件判断
#if 0
	printf("0\n");
#else
	printf("1\n");
#endif


return 0;

}