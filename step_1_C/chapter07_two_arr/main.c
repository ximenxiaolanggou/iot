#include<stdio.h>

int main() {
	int arr[3][4] = {{11,12,13,14},{21,22,23,24},{31,32,33,34}};
	int arr2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int i,j;

	for(i = 0 ; i < 3 ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d\t", arr[i][j]);
		}
			printf("\n");
	}

}