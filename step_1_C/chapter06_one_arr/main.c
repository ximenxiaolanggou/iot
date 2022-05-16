#include<stdio.h>

int main() {
	int arr[10];
	int arr2[5] = {1,2,3,4,5};
	int arr3[5] ={0};// 初始化数组都为0
	int i;
	int j;
	int k;

	for(i = 0 ; i < 10 ; i++)
	{
		printf("%d\n", arr[i]);
	}

	for(j = 0 ; j < 5 ; j++)
	{
		printf("%d\n", arr2[j]);
	}

	printf("sizeof：%d\n", sizeof(arr2));

	for(k = 0 ; k < 5 ; k++)
	{
		printf("%d\n", arr3[k]);
	}
}