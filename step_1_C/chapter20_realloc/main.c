#include<stdio.h>
#include<stdlib.h>

int main() {
 
	int num;
	int num2;
	int *arr = NULL;
	int i;

    printf("������Ԫ�ظ�����");
	scanf("%d", &num);

	arr = (int *)calloc(num, sizeof(int));

	if(NULL == arr) {
	 perror("malloc");
	 return;
	}
	


	for(i = 0 ; i < num ; i++) {
		scanf("%d", arr + i);
	
	}

	 printf("��ڶ�������Ԫ�ظ�����");
	 scanf("%d", &num2);

	 arr = (int *)realloc(arr, (num + num2) * sizeof(int));

	 for( ;i < (num + num2) ; i++) {
		scanf("%d", arr + i);
	
	}

	
	for(i = 0 ; i < (num + num2) ; i++) {
		printf("%d\n", arr[i]);
	
	}

	free(arr);

	return 0;
}