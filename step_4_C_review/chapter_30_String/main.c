#include<stdio.h>
#include<string.h>
#include <stdlib.h>

// 字符串长度
int strLen(char *str)
{
    int len = strlen(str);
    printf("字符串长度为：%d\n", len);
    return len;
}

// 字符串拷贝
void strCopy()
{
    char dest[32] = "hello world";
    char target[32] = "hello java";

    strcpy(dest, target);
    printf("dest:%s\n", dest);
}

// 字符串追加
void strConcat()
{
    char dest[32] = "hello world";
    char target[32] = " hello java";
    strcat(dest, target);
     printf("dest:%s\n", dest);
}

// 字符串比较
void strComp()
{
    char str1[32] = "hello world";
    char str2[32] = "hello java";
    int res = strcmp(str1,str2);
    printf("比较结果为：%d\n", res);

    // 比较前四个字符

    printf("前四个字符比较结果为：%d\n", strncmp(str1,str2,4));
    printf("前七个字符比较结果为：%d\n", strncmp(str1,str2,7));
}

// 字符查找
void strChr()
{
    char str1[32] = "hello world";
    //找第一个匹配的字符
    char *ret = strchr(str1, 'w');
    //找最后一个匹配的字符
    //char *ret = strrchr(str1[32], 'w');
    if(ret == NULL)
    {
        printf("未找到\n");
    }
    else{
       printf("找到了，在数组的第%d个位置\n", ret - str1); 
    }
}

/// 字符串查找
void strStr()
{
    char str1[32] = "hello world";
    char *ret = strstr(str1, "wo");
    if(ret == NULL)
    {
        printf("未找到\n");
    }
    else{
       printf("找到了，在数组的第%d个位置\n", ret - str1); 
    }
}

// 字符串转数值
void strToInt()
{
    char *str = "123";
    int res = atoi(str);
    printf("%d\n", res);

    //使用atof将浮点型的字符串转化为浮点型数据
    char s2[] = "3.1415926";
    double ret2 = atof(s2);
    printf("ret2 = %lf\n", ret2);
}

// 字符串切割
void strTok()
{
    //使用strtok函数切割字符串
    char s[] = "111:22222:33:4444444444:5555555555555";
    char *ret;
    //第一次切割
    ret = strtok(s, ":");
    printf("ret = %s\n", ret);

    //后面所有切割时都要将strtok的第一个参数传NULL
    while((ret = strtok(NULL, ":")) != NULL)
    {
        printf("ret = %s\n", ret);
    }


}

// 字符串格式化
void strFormat()
{
    char buf[20];
    int a, b, c;
    sprintf(buf, "%d-%d-%d",2013,12,12);

    printf("%s\n", buf);

    sscanf("2013:10:1", "%d:%d:%d", &a, &b, &c);
    printf("a=%d,b=%d,c=%d\n",a,b,c);
}

// 字符串格式化 - 高级用法
void strFormatHigh()
{
    //1、跳过数据：%*s或%*d
    char buf1[20];
     sscanf("1234 5678","%*d %s",buf1);
    printf("%s\n",buf1);

    //2、读指定宽度的数据：%[width]s
    char buf2[20];
    sscanf("12345678","%4s ",buf2);
    printf("%s\n",buf2);

    //3、支持集合操作：只支持获取字符串
    // %[a‐z] 表示匹配a到z中任意字符(尽可能多的匹配)
    // %[aBc] 匹配a、B、c中一员，贪婪性
    // %[^aFc] 匹配非a、F、c的任意字符，贪婪性
    // %[^a‐z] 表示读取除a‐z以外的所有字符
    char buf3[20];
    sscanf("agcd32DajfDdFF","%[a-z]",buf3);
    printf("%s\n",buf3);

}

int main()
{
    strLen("hello world");
    strCopy();
    strConcat();
    strComp();
    strChr();
    strStr();
    strToInt();
    strTok();
    strFormat();
    strFormatHigh();
    return 1;
}