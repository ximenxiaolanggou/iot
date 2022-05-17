#include<stdio.h>


void test_01() {
	int num = 10;
	int *p = &num;

	printf("%p\n", &num);

	printf("%p\n",p);

}

void test_02() {
	int num = 10;
	int *p = &num;

	printf("%d\n", *p); // 获取地址编号对应的内容


}

void test_03() {
	int num = 10;
	int *p = &num;

	*p = 100; // 给*p赋值等于给num赋值

	printf("%d\n", num);
	printf("%d\n", *p);


}

void test_04() {
  int num = 0x01020304;
  int *p = &num;
  char *c = &num;
  printf("%x\n", *p);
  printf("%x\n", *c);

}

// 跨度和宽度问题
void test_05() {
  int num = 0x01020304; 
  int *p = &num;
  char *c = &num;
  short *s = &num;

  // 获取 0x0203;
  printf("%#x\n", *(short *)(c + 1));
  // 获取 0x0203;
  printf("%#x\n", *(short *)((char *)s + 1));

}
int main() {

	test_05();

	return 0;
}