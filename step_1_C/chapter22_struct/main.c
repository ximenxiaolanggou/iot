#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stu {
	int id;
	char name[100];
	int age;
};

// �����ṹ��
void test01() {
	struct stu zhangsan = {1, "����",10};

	printf("ѧ��%d\n",zhangsan.id);
	printf("����%s\n",zhangsan.name);
	printf("����%d\n",zhangsan.age);
	
}

// ��������
void test02() {

	struct stu zhangsan;
	// �������
	memset(&zhangsan,0, sizeof(zhangsan));

	scanf("%d %s %d",&zhangsan.id, zhangsan.name,&zhangsan.age);

	printf("ѧ��%d\n",zhangsan.id);
	printf("����%s\n",zhangsan.name);
	printf("����%d\n",zhangsan.age);

}

// �ṹ������
void test03() {
	struct stu arr[4] = {
		{1, "����",10},
		{2, "����",10},
		{3, "����",10},
		{4, "����",10}
	};
}

// ��������ѧ����Ϣ����ƽ������
void test04() {

	struct stu arr[3];
	int i;
	int sum = 0;
	int num = sizeof(arr) / sizeof(arr[0]);
	memset(&arr,0,sizeof(arr)); // �������

	
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