#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	float a = -12.3;
	char buffer[32];
	sprintf(buffer, "%f", a);
	printf("%s\n", buffer);
	printf("hello world\n");
	return 0;
}