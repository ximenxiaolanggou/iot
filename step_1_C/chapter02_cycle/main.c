#include <stdio.h>
#define PI 3.14

int main(int argc, char *argv[]) {

	float r = 0.0f;
	float area = 0.0f;

	scanf("%f", &r);
	area = PI * r * r;

	 //printf("area: %f.2\n", area); // 保留两位小数
	printf("area: %f\n", area);

	return 0;
}