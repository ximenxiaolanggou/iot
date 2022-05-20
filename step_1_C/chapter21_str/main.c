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