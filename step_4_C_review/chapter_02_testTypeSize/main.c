#include<stdio.h>

int main() {
       
    char a;
    short b;
    int c;
    long d;
    float e;
    double f;



    //sizeof：是一个运算符，可以获取数据类型所占内存的大小
    printf("char占内存：%d\n", sizeof(a));
    printf("short占内存：%d\n", sizeof(b));
    printf("int占内存：%d\n", sizeof(c));
    printf("long占内存：%d\n", sizeof(d));
    printf("float占内存：%d\n", sizeof(e));
    printf("double占内存：%d\n", sizeof(f));

    return 1;
}