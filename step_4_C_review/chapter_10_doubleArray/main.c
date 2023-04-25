#include<stdio.h>
int main()
{

    // 定义一个二维数组
    int arr[2][4];

    printf("%d\n", sizeof(arr));

    //二维数组的行数可以省略，但是列数不能省略，在初始化时可以这样操作
    //系统会根据列数自动指定行数，最终得到的函数所得到得元素个数移动是列的整数倍
    int arr2[][4] = {1,2,3,4,5};
    printf("%d\n", sizeof(arr2));
    return 1;
}