#include<stdio.h>


// �Զ���int
typedef int MY_INT;
// �Զ�������
typedef int MY_ARR[5];
// �Զ���ָ��
typedef int *MY_POINT;
// �Զ��庯��ָ��
typedef int (*MY_SUM_FUN)(int a, int b);
// �Զ���ṹ��
typedef struct {
	int id;
	char name[100];
}STU;


int sumFun(int a, int b) {
	return a + b;
}



int main() {

	MY_INT a = 1;
	MY_INT b = 2;
	MY_ARR nums = {1,2,3,4};
	MY_POINT aP = &a;
	STU zhangsan = {1,"����"};
	// �ṹ��ָ��
	STU *p = &zhangsan;

	MY_SUM_FUN my_fun = sumFun;

	printf("a%d\n", a);
	printf("b:%d\n", b);
	printf("arr:%d\n", nums[0]);
	printf("aP:%d\n", *aP);
	printf("my_fun:%d\n", my_fun(a,b));
	printf("name:%s\n", zhangsan.name); 
	// �ṹ��ָ���ȡ�ṹ������
	printf("id:%d\n", p->id);
	printf("id:%s\n", *p->name);

}



