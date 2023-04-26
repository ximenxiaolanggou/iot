#include<stdio.h>

int main()
{
    int a[10];

    int *p, *q;

    //p和q间隔8个字节，意味着加一个整数最终移动的字节数与指针变量的类型也有关系
    p = a;
    q = p + 2;

    printf("p = %p\n", p);
    printf("q = %p\n", q);

    return 0;
}