#include <stdio.h>

int main(int argc, char *argv[]) {

	int one = 0;
	int two = 0;
	int res = 0;

	printf("请输入第两个整数，以空格隔开\n");

	// scanf 终端上怎么输入，这边就怎么写格式
	scanf("%d %d", &one, &two);

	res = sum(one,two);
	
	printf("res: %d\n",res);

}

int sum(int one, int two) {

	return one + two;
}