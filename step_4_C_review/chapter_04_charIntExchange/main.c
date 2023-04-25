#include<stdio.h>

int main ()
{

    char a = 'W';

    int b = 1000;


    // 字符a遇到%d会输出ASCII
    printf("%c，%d\n", a, a);

    // 字符b遇到%C会输出ASCII对应字符
    printf("%c，%d\n", b, b);

    return 1;
}