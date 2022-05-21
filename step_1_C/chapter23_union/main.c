#include<stdio.h>

union stu {
	int id;
	char c;

};

int main() {
	union stu zhangsan;

	zhangsan.id = 1;
	zhangsan.c = 'a';

	printf("%d\n",zhangsan.id);
	
}