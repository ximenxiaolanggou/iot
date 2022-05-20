#include<stdio.h>
#include<stdlib.h>

int main() {
 
	int num;
	int *arr = NULL;
	int i;

    printf("请输入元素个数：");
	scanf("%d", &num);

	arr = (int *)calloc(num,sizeof(int)); // 申请内存成功并会自动清空申请的内存数据

	if(NULL == arr) {
	 perror("malloc");
	 return;
	}
	

	for(i = 0 ; i < num ; i++) {
		scanf("%d", arr + i);
	
	}

	for(i = 0 ; i < num ; i++) {
		printf("%d\n", arr[i]);
	
	}

	free(arr);
}