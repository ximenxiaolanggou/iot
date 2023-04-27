#include<stdio.h>

struct packed_data{
    unsigned int a:2;
    unsigned int b:6;
    unsigned int c:4;
    unsigned int d:4;
    unsigned int i;
} data;

struct stu{
    char a:7;
    char b:7;
    char c:2;
}temp;

int main()
{
    printf("%d\n",sizeof(data));
    printf("%p\n",&data);
    printf("%p\n",&(data.i));


    printf("%d\n",sizeof(temp)); //结果为：3 ，证明位段不能跨其存储单元存储
}