#include<stdio.h>

#define PI 3.1415926

#define S(a, b) ((a)*(b))


int main()
{
    int r = 2;

    printf("圆的面积为：%.3f\n", r * r * PI);


    printf("%d\n", S(2, 4));

    //注意：宏定义只是简单的替换，不会自动加括号
    //带参宏1：2 + 8 * 4 = 34
    //带参宏2：((2 + 8) * (4)) = 40
    printf("%d\n", S(2 + 8, 4));

    return 1;
}