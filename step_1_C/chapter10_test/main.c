#include<stdio.h>

int main() {
	
	char arr[11] = "";

	int i;
	int j;
	char temp;

	fgets(arr, sizeof(arr), stdin);

	printf("%s\n", arr);
	for(i = 0 ; i < 9 ; i++) {
		for(j = (1 + i) ; j < 10 ; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				printf("%s\n", arr);
			}

		}

	}
	
	printf("end\n");
	printf("%s\n", arr);

	return 0;

}