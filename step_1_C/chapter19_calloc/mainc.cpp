#include<stdio.h>
#include<stdlib.h>

int main() {
 
	int num;
	int *arr = NULL;
	int i;

    printf("������Ԫ�ظ�����");
	scanf("%d", &num);

	arr = (int *)calloc(num,sizeof(int)); // �����ڴ�ɹ������Զ����������ڴ�����

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