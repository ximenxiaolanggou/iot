#include<stdio.h>

int main()
{
    // 定义一个变量
    int a = 100;

    // 定义一个指针
    int* p;

    // 将指针变量赋值
    // 将a的地址保存在p中
    p = &a;

    printf("a = %d %d\n", a, *p);

    printf("&a = %p %p\n", p, &a);


    printf("sizeof(a) = %d\n", sizeof(p));


    return 1;
}