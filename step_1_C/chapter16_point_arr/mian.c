#include<stdio.h>

void test_01() {
	int arr[5] = {1,2,3,4};
	int i;
	int *p;
	p = &arr[0];
	for(i = 0 ; i < 5 ; i++) {
	
		printf("%d\n",arr[i]);
		printf("%d\n",*(p + i));
	}
}


// 指针数组
void test_02() {
	int a = "10";
	int b = "20";
	int c = "30";


	int *arr[3] = {&a,&b,&c};

	char *arr2[3] = {"hehe","haha","heihei"};

	printf("%s\n", arr2[1]);
	printf("%c\n", *(arr2[1] + 1));

}

// 数组指针
void test_03() {
	int a[3][4] = {11,12,13,14,21,22,23,24,31,32,33,34};
	int (*p)[4];

	printf("%p\n",a);
	printf("%p\n",a + 1);

	p = a;
	printf("%p\n",p);
	printf("%p\n",p + 1);

	printf("\n");
	printf("%d\n", *(*(p + 0) + 1));

}

int main() {
	
	test_03();
	return 0;

}