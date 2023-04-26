#include<stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5};


    int *p = &arr;

    printf("arr[2]值为：%d\n", arr[2]);

    printf("p[2]值为：%d\n", p[2]);

    printf("*(p + 2)值为：%d\n", *(p + 2));

    return 1;
}