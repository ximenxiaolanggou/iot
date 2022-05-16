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

