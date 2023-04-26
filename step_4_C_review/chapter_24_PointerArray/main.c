#include<stdio.h>

void charPointerArr()
{
    char *name[3] = {"zhangsan", "lisi", "wangwu"};

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", name[i]);
    }
    
}

int main()
{
    charPointerArr();
    return 1;
}