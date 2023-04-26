#include<stdio.h>

int main()
{
    int a = 100;

    //定义一个一级指针
    int *p = &a;

    //定义一个二级指针
    int **q = &p;

    printf("a = %d %d %d\n", a, *p, **q);

    return 1;
}