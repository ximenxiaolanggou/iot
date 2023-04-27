#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 struct stu{
	int num;
	char name[20];
	char sex;
};

 typedef struct{
	int num;
	char name[20];
	char sex;
}STU;

int main()
{

    // 定义结构体指针
    struct stu *stu1;

    // 申请内存

    stu1 = (struct stu *)calloc (1, sizeof(struct stu));

    //  stu1 = (STU *)calloc (1, sizeof(STU));

    stu1 -> num = 10;

    strcpy(stu1 -> name, "zhangsan");

    stu1 ->sex = 'A';

    printf("num:%d,name:%s,sex:%c\n", stu1 -> num, stu1 -> name, stu1 -> sex);

}