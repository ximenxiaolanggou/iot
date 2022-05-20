#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stu {
	int id;
	char name[100];
	int age;
};

// 创建结构体
void test01() {
	struct stu zhangsan = {1, "张三",10};

	printf("学号%d\n",zhangsan.id);
	printf("姓名%s\n",zhangsan.name);
	printf("年龄%d\n",zhangsan.age);
	
}

// 键盘输入
void test02() {

	struct stu zhangsan;
	// 清空数据
	memset(&zhangsan,0, sizeof(zhangsan));

	scanf("%d %s %d",&zhangsan.id, zhangsan.name,&zhangsan.age);

	printf("学号%d\n",zhangsan.id);
	printf("姓名%s\n",zhangsan.name);
	printf("年龄%d\n",zhangsan.age);

}

// 结构体数组
void test03() {
	struct stu arr[4] = {
		{1, "张三",10},
		{2, "李四",10},
		{3, "王五",10},
		{4, "赵六",10}
	};
}

// 键盘输入学生信息，求平均年龄
void test04() {

	struct stu arr[3];
	int i;
	int sum = 0;
	int num = sizeof(arr) / sizeof(arr[0]);
	memset(&arr,0,sizeof(arr)); // 清空数组

	
	for(i = 0 ; i < num ; i++) {
		scanf("%d %s %d",&arr[i].id, arr[i].name,&arr[i].age);
	}

	i = 0;

	for(i = 0 ; i < num ; i++) {

		sum += arr[i].age;
	}
	printf("avg:%f\n",(float)sum / num);


}	

int main() {
	test04();
	return 0 ;
}