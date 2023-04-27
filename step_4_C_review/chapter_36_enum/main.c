#include <stdio.h>

//定义一个枚举类型
enum week
{
    mon = 8,
    tue,
    wen,
    thu,
    fri,
    sat,
    sun
};


int main()
{
    //定义枚举类型的变量
    enum week day = mon;
    printf("day = %d\n", day);
    day = fri;
    printf("day = %d\n", day);
}