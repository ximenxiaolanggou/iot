#include <stdio.h>

int main(int argc, char *argv[]) {

	int one = 0;
	int two = 0;
	int res = 0;

	printf("������������������Կո����\n");

	// scanf �ն�����ô���룬��߾���ôд��ʽ
	scanf("%d %d", &one, &two);

	res = sum(one,two);
	
	printf("res: %d\n",res);

}

int sum(int one, int two) {

	return one + two;
}