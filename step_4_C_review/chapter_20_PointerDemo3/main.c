#include<stdio.h>

int main()
{
    int a = 0x1234, b = 0x5678;

    char *p1, *p2;

    printf("%#x %#x\n", a, b);

    p1 = (char *)&a;
    p2 = (char *)&b;

    // *+指针 取值，取几个字节，由指针类型决定的指针为字符指针则取一个字节
    printf("%#x %#x\n", *p1, *p2);

    p1++;
    p2++;

    printf("%#x %#x\n",*p1,*p2);

    return 1;
}