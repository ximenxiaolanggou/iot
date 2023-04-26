#include<stdio.h>

// 指针函数
char *fun()
{
    char *name = "zhangsan";

    return name;
}

int main()
{
    char *name = fun();

    printf("%s\n", name);

}