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

	printf("%d\n", *p); // ��ȡ��ַ��Ŷ�Ӧ������


}

void test_03() {
	int num = 10;
	int *p = &num;

	*p = 100; // ��*p��ֵ���ڸ�num��ֵ

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

// ��ȺͿ������
void test_05() {
  int num = 0x01020304; 
  int *p = &num;
  char *c = &num;
  short *s = &num;

  // ��ȡ 0x0203;
  printf("%#x\n", *(short *)(c + 1));
  // ��ȡ 0x0203;
  printf("%#x\n", *(short *)((char *)s + 1));

}
int main() {

	test_05();

	return 0;
}