#include<stdio.h>


// 自定义int
typedef int MY_INT;
// 自定义数组
typedef int MY_ARR[5];
// 自定义指针
typedef int *MY_POINT;
// 自定义函数指针
typedef int (*MY_SUM_FUN)(int a, int b);
// 自定义结构体
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
	STU zhangsan = {1,"张三"};
	// 结构体指针
	STU *p = &zhangsan;

	MY_SUM_FUN my_fun = sumFun;

	printf("a%d\n", a);
	printf("b:%d\n", b);
	printf("arr:%d\n", nums[0]);
	printf("aP:%d\n", *aP);
	printf("my_fun:%d\n", my_fun(a,b));
	printf("name:%s\n", zhangsan.name); 
	// 结构体指针获取结构体数据
	printf("id:%d\n", p->id);
	printf("id:%s\n", *p->name);

}



