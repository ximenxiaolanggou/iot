#include<stdio.h>
#include<stdlib.h>

int main() {
 
	int num;
	int *arr = NULL;
	int i;

    printf("������Ԫ�ظ�����");
	scanf("%d", &num);

	arr = (int *)malloc(4 * num);

	if(NULL == arr) {
	 perror("malloc");
	 return;
	}
	
	memset(arr,0, num*sizeof(int));

	for(i = 0 ; i < num ; i++) {
		scanf("%d", arr + i);
	
	}

	for(i = 0 ; i < num ; i++) {
		printf("%d\n", arr[i]);
	
	}
}