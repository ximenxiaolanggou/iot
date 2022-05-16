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