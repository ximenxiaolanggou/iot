#include<stdio.h>

int main()
{
    // 定义一个字符数组，通过scanf函数输入字符串并输出结果
    // 通过赋值""这样的方式可以清除字符数组中的垃圾字符，让每一个元素都是\0
    char str[32] = "";

    // 数组名就是当前数组的首地址，所以scanf的第二个参数直接传数组名即可
    scanf("%s", str);

    printf("输入的内容是：%s\n", str);

    return 0 ;

}