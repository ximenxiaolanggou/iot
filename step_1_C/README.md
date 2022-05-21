# Visiual C++ 6 安装

VC6.0 完整绿色版下载地址1：https://pan.baidu.com/s/1nxee1AD 提取密码：wdhk

VC6.0 完整绿色版下载地址2：https://pan.baidu.com/s/1qZGYtiO 提取密码：ix5p

**TIP：**地址来源 http://c.biancheng.net/view/463.html

# 键盘输入 scanf("",&)

```c
#include <stdio.h>
#define PI 3.14

int main(int argc, char *argv[]) {

	float r = 0.0f;
	float area = 0.0f;

	scanf("%f", &r);
	area = PI * r * r;

    //printf("area: %f.2\n", area);
	printf("area: %f\n", area);

	return 0;
}
```

# 宏定义

```c
#define PI 3.14
```

# 函数和函数调用

```c
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
```

# 数据类型和占用空间大小

## byte short int long float double

```c
#include<stdio.h>

int main () {

	printf("char: %d\n",sizeof(char));
	printf("short: %d\n",sizeof(short));
	printf("int: %d\n",sizeof(char));
	printf("long: %d\n",sizeof(long));
	printf("float: %d\n",sizeof(float));
	printf("double: %d\n",sizeof(double));
}
```

## singned （默认）、unsingned

## struct、union、enum、void

## sizeof、typedef、register

# goto

```c
#include<stdio.h>

int main() {
	printf("1111111111\n");
	goto NEXT;
	printf("2222222222\n");
	printf("3333333333\n");
	printf("4444444444\n");
NEXT:
	printf("5555555555\n");
	printf("6666666666\n");

}
```

# 字符数组

```c
#include<stdio.h>

int main() {

	char arr[] = {'h','e','l','l','o','\0'};

	char arr2[] = "hello";

	char arr3[3][10] = {"hehe", "hahha","heihei"};

	printf("%s\n", arr);
	printf("%s\n", arr2);	
}
```

# 获取键盘字符串

```c
#include<stdio.h>

int main() {

	char buf[5] = "";

	//scanf("%s", &buf); // 输入内容不能存在空格

	//gets(buf); // 当输入内容超过buf缓冲区大小会造成其他内存数据污染
	
	fgets(buf, sizeof(buf), stdin);

	printf("%s\n",buf);
}
```

# Demon 

asdasdasdasdasdasdadsfa -> abcdefj...

```c
#include<stdio.h>

int main() {
	
	char arr[11] = "";

	int i;
	int j;
	char temp;

	fgets(arr, sizeof(arr), stdin);

	printf("%s\n", arr);
	for(i = 0 ; i < 9 ; i++) {
		for(j = (1 + i) ; j < 10 ; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				printf("%s\n", arr);
			}

		}

	}
	
	printf("end\n");
	printf("%s\n", arr);

	return 0;

}
```

# extern 外部文件引入

## main.c

```c
#include<stdio.h>

extern int data;
void print(void) {

	printf("%d\n",data);
}
```

## fun.c

```c
#include<stdio.h>

extern void print(void);
extern int data;
int main(){

	print();
}

int data = 100;
```

# 宏

```c
#include<stdio.h>

#define A 10

#define B(a,b) a*b

#define C(a,b) (a)*(b)


int main() {


	printf("%d\n",A);

	printf("%d\n",B(10+10,20+20));

	printf("%d\n",C(10+10,20+20));

// 未定义宏
#ifdef D
	printf("定义D\n");
#else
	printf("未定义D\n");
#endif

// 定义宏
#ifndef D
	printf("未定义D\n");
#else
	printf("定义D\n");
#endif

	// 条件判断
#if 0
	printf("0\n");
#else
	printf("1\n");
#endif
	return 0;

}
```

# 防止头文件重复包含

## 在头文件添加#pragma once // 防止文件重复包含

## C/C++ 的标准指定

```c
#ifndef 宏
#define 宏
	头文件具体内容
#endif
```

在头文件（a.h）中编写

```c
#ifndef __A_H__
#define __A_H__
#include "b.h" // 头文件需要写在中间
#endif
```

# 动态申请内存地址

## malloc 申请内存

## free 释放内存

## memset 清空数据

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
 
	int num;
	int *arr = NULL;
	int i;

    printf("请输入元素个数：");
	scanf("%d", &num);

	arr = (int *)malloc(4 * num);

	if(NULL == arr) {
	 perror("malloc");
	 return;
	}
	
	memset(arr,0, num*sizeof(int));

	for(i = 0 ; i < num ; i++) {
		scanf("%d", arr + i);
	}

	for(i = 0 ; i < num ; i++) {
		printf("%d\n", arr[i]);
	
	}

	free(arr);


}
```

## calloc函数

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
 
	int num;
	int *arr = NULL;
	int i;

    printf("请输入元素个数：");
	scanf("%d", &num);

	arr = (int *)calloc(num,sizeof(int)); // 申请内存成功并会自动清空申请的内存数据

	if(NULL == arr) {
	 perror("malloc");
	 return;
	}
	

	for(i = 0 ; i < num ; i++) {
		scanf("%d", arr + i);
	
	}

	for(i = 0 ; i < num ; i++) {
		printf("%d\n", arr[i]);
	
	}

	free(arr);
}
```



## realloc函数

 ```c
 #include<stdio.h>
 #include<stdlib.h>
 
 int main() {
  
 	int num;
 	int num2;
 	int *arr = NULL;
 	int i;
 
     printf("请输入元素个数：");
 	scanf("%d", &num);
 
 	arr = (int *)calloc(num, sizeof(int));
 
 	if(NULL == arr) {
 	 perror("malloc");
 	 return;
 	}
 	
 
 
 	for(i = 0 ; i < num ; i++) {
 		scanf("%d", arr + i);
 	
 	}
 
 	 printf("请第二次输入元素个数：");
 	 scanf("%d", &num2);
 
 	 arr = (int *)realloc(arr, (num + num2) * sizeof(int));
 
 	 for( ;i < (num + num2) ; i++) {
 		scanf("%d", arr + i);
 	
 	}
 
 	
 	for(i = 0 ; i < (num + num2) ; i++) {
 		printf("%d\n", arr[i]);
 	
 	}
 
 	free(arr);
 
 	return 0;
 }
 ```

# 字符串函数

## strlen长度

## strcpy 拷贝

## strncpy 前n个拷贝

## strcmp 比较

## strncmp 前n个比较

## strchar 字符中查找第一次字符出现的位置

 ## strstr 字符串中查找第一次字符出现的位置

  ## atoi/atol/atof 字符串转换数值

## strtok 字符串切割

## sprintf 格式化字符串操作函数 - 组包

## scanf - 解包

 ## const 

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void test01() {
	char arr[100] = "damoncai";
	char distArr[100] = "";
	char distArr2[100] = "";

	char str[20]="aa\0aaaaaaaaaaaaaaaaa";
	char *src ="hello";

	int len;
	// 字符串长度
	len = strlen(arr);
	printf("长度为:%d\n",len);

	// 拷贝字符串
	strcpy(distArr,arr);
	printf("distArr:%s\n",distArr);

	// 拷贝字符串 - 设置长度 strncpy
	strncpy(distArr2,arr,4);
	printf("distArr2:%s\n",distArr2);

	// 链接字符
	//strcat(str,src);
	//printf("%s\n",str);

	strncat(str,src, 2);
	printf("%s\n",str);
}

// 自定义字符串拷贝
void test02(char *des, char *src) {
	
	while(*src != '\0') {
		*des = *src;
		src++;
		des++;
	}
		
}

// 字符查找
void test03() {
	char src[100] = "damoncai";
	char *des = NULL;
	des = strchr(src,'o');
	if(des != NULL) {
		*des = '#';	
	}
	printf("%s\n",src);
}

// 字符串查找
void test04() {
	char src[100] = "www.sex.hello.sex.com";
	char *tip = NULL;

	do{
		tip = strstr(src,"sex");
		if(tip != NULL) memset(tip,'#',3);
	}while(tip != NULL);
	printf("%s\n",src);
}

// 字符串转化成数字类型
void test05() {
	
	printf("atoi:%d\n",atoi("123"));
	printf("atol:%ld\n",atol("12345"));
	printf("atof:%f\n",atof("12.3"));

}

// 字符串切割
void test06() {
	char str[] = "hehe:haha:heihei";
	char *names[100] = {NULL};
	int	i = 0;
	do {
		if(i == 0) {
			names[i] = strtok(str, ":");
		}else {
			names[i] = strtok(NULL,":"); // : 可以写@#: 表示按照这三个字符切割
		}

		printf("%s\n", names[i]);
	}while(names[i++] != NULL);

	i = 0;

	while(names[i] != NULL) {
		printf("%s\n", names[i]);
		i++;
	}


}

void test07() {
	char *p1 = "damoncai";
	char p2[] = "damoncai";

	printf("%s\n",p1);
	printf("%s\n",p2);
}

// 组包
void test08() {
	char arr[100] = "";
	int len;
	len = sprintf(arr,"%d年%d月%d日\n", 2022, 12, 12);
	printf("长度:%d\n",len);
	printf("数据:%s", arr);
	
}

// 解包 - sscanf
void test09() {
	char buf[20];
	char arr[100] = "2022年12月12日";
	int year;
	int month;
	int data;
	sscanf(arr,"%d年%d月%d日\n", &year, &month, &data);
	printf("年:%d\n",year);
	printf("月:%d\n",month);
	printf("日:%d\n",data);

	sscanf("1234 5678","%*d %s",buf);//跳过 1234 ,然后隔一个空格获取字符串
	printf("%s\n",buf);
	
}

// 解包 - sscanf - 高级用法 1 跳过提取内容
void test10() {
	char buf[20];

	sscanf("1234 5678","%*d %s",buf);//跳过 1234 ,然后隔一个空格获取字符串
	printf("%s\n",buf);
	
}

// 解包 - sscanf - 高级用法 2 提取指定长度的字符串
void test11() {
	char buf[20];
	sscanf("12345678","%4s ",buf);//从字符串中获取字符串，只要 4 个字节，存放在 buf 中
	printf("%s\n",buf);
	
}

// 解包 - sscanf - test
void test13() {
	char buf[20];
	sscanf("agcd32DajfDdFF","%[a-z]",buf);//从字符串中获取输入只要’a’和’z’之间的字符，碰到不在范围内的，就终止了千锋智能物联网学院
	printf("%s\n",buf);//结果为 agcd

	/*
		%[aBc] 匹配 a、B、c 中一员，贪婪性
		%[^aFc] 匹配非 a Fc 的任意字符，贪婪性
		%[^a-z]表示读取除 a-z 以外的所有字符	
	*/
	
}

// 解包 - sscanf - test
void test14() {
	int data1 = 0;
	int data2 = 0;
	char buf[16] = "";

	sscanf("12345678","%*2s%2d%*2s%s",&data2,buf); // data2 = 34 buf="78"
	printf("%d\n",data2);
	printf("%s\n",buf);
	
}

int main() {
	char src[100] = "damoncai";
	char des[100] = "";

	test12();

	return 0;
}
```

# 结构体

```c
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
```

# typedef 

```c
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
```

# 位段

```c
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
```

# union共用体

```c
#include<stdio.h>

union stu {
	int id;
	char c;

};

int main() {
	union stu zhangsan;

	zhangsan.id = 1;
	zhangsan.c = 'a';

	printf("%d\n",zhangsan.id);
	
}
```

# enum 枚举

```c
#include<stdio.h>

enum week //枚举类型
{
mon，tue，wed，thu，fri，sat,sun
};
int main() {

enum week workday,weekday;//枚举变量 workday 与 weekday 只能取 sun….sat 中的一个

}
```

# 文件
