#include<stdio.h>

int main ()
{

    
    int a = 100;
    // 输出十进制整数
    printf("%d\n", a);

    // 输出八进制数
    printf("%o\n", a);

    //使用%#o，可以输出八进制数的前导符
    printf("%#o\n", a);

    //输出十六进制数
    printf("%x\n", a);

    // 使用%#x，可以输出十六进制数的前导符
    printf("%#x\n", a);
    
    //输出浮点型数据,float使用%f，double使用%lf
    //默认小数点后保留六位，并且可以四舍五入，如果不够六位自动补0
    float b = 3.1415926;
    double c = 2345.2345;
    printf("b = %f\n", b);
    printf("c = %lf\n", c);


    //输出字符，使用%c输出字符，使用%d可以输出字符的ascii码值
    char d = 'y';
    printf("d = %c %d\n", d, d);



     //输出字符串，使用%s
     //没有专门的变量保存字符串，一般使用数组来保存
    char e[] = "hello world";
    printf("e = %s\n", e);

    //输出地址，使用%p
    //&：取一个变量的地址，一般地址用十六进制数标识
    printf("%p\n", &a);

    return 1;

}