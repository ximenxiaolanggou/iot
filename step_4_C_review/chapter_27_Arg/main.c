#include<stdio.h>

// 一维数组传参
void fun1(int *p)
{
    printf("%d\n", p[2]);
}

// 二位维数组传参
void fun2(int (*p)[3])
{
    printf("%d\n", (*(p +  1))[1]);
    // 可以写成
    printf("%d\n", *(*(p +  1) + 1));
}

// 指针数组
void fun3(char **name)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", name[i]);
    }
    
}

int main()
{
    int arr1[] = {1,2,3};
    fun1(arr1);

    int arr2[][3] = {1,2,3,4,5,6};
    fun2(arr2);

    char *name[3] = {"zhangsan", "lisi", "wangwu"};
    fun3(name);
}