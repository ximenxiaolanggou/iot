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
	// �ַ�������
	len = strlen(arr);
	printf("����Ϊ:%d\n",len);

	// �����ַ���
	strcpy(distArr,arr);
	printf("distArr:%s\n",distArr);

	// �����ַ��� - ���ó��� strncpy
	strncpy(distArr2,arr,4);
	printf("distArr2:%s\n",distArr2);

	// �����ַ�
	//strcat(str,src);
	//printf("%s\n",str);

	strncat(str,src, 2);
	printf("%s\n",str);
}

// �Զ����ַ�������
void test02(char *des, char *src) {
	
	while(*src != '\0') {
		*des = *src;
		src++;
		des++;
	}
		
}

// �ַ�����
void test03() {
	char src[100] = "damoncai";
	char *des = NULL;
	des = strchr(src,'o');
	if(des != NULL) {
		*des = '#';	
	}
	printf("%s\n",src);
}

// �ַ�������
void test04() {
	char src[100] = "www.sex.hello.sex.com";
	char *tip = NULL;

	do{
		tip = strstr(src,"sex");
		if(tip != NULL) memset(tip,'#',3);
	}while(tip != NULL);
	printf("%s\n",src);
}

// �ַ���ת������������
void test05() {
	
	printf("atoi:%d\n",atoi("123"));
	printf("atol:%ld\n",atol("12345"));
	printf("atof:%f\n",atof("12.3"));

}

// �ַ����и�
void test06() {
	char str[] = "hehe:haha:heihei";
	char *names[100] = {NULL};
	int	i = 0;
	do {
		if(i == 0) {
			names[i] = strtok(str, ":");
		}else {
			names[i] = strtok(NULL,":"); // : ����д@#: ��ʾ�����������ַ��и�
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

// ���
void test08() {
	char arr[100] = "";
	int len;
	len = sprintf(arr,"%d��%d��%d��\n", 2022, 12, 12);
	printf("����:%d\n",len);
	printf("����:%s", arr);
	
}

// ��� - sscanf
void test09() {
	char buf[20];
	char arr[100] = "2022��12��12��";
	int year;
	int month;
	int data;
	sscanf(arr,"%d��%d��%d��\n", &year, &month, &data);
	printf("��:%d\n",year);
	printf("��:%d\n",month);
	printf("��:%d\n",data);

	sscanf("1234 5678","%*d %s",buf);//���� 1234 ,Ȼ���һ���ո��ȡ�ַ���
	printf("%s\n",buf);
	
}

// ��� - sscanf - �߼��÷� 1 ������ȡ����
void test10() {
	char buf[20];

	sscanf("1234 5678","%*d %s",buf);//���� 1234 ,Ȼ���һ���ո��ȡ�ַ���
	printf("%s\n",buf);
	
}

// ��� - sscanf - �߼��÷� 2 ��ȡָ�����ȵ��ַ���
void test11() {
	char buf[20];
	sscanf("12345678","%4s ",buf);//���ַ����л�ȡ�ַ�����ֻҪ 4 ���ֽڣ������ buf ��
	printf("%s\n",buf);
	
}

// ��� - sscanf - test
void test13() {
	char buf[20];
	sscanf("agcd32DajfDdFF","%[a-z]",buf);//���ַ����л�ȡ����ֻҪ��a���͡�z��֮����ַ����������ڷ�Χ�ڵģ�����ֹ��ǧ������������ѧԺ
	printf("%s\n",buf);//���Ϊ agcd

	/*
		%[aBc] ƥ�� a��B��c ��һԱ��̰����
		%[^aFc] ƥ��� a Fc �������ַ���̰����
		%[^a-z]��ʾ��ȡ�� a-z ����������ַ�	
	*/
	
}

// ��� - sscanf - test
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