#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int id;
	char name[100];
	int age;
}HERO;

// ��ȡ�ļ� - c
void test01() {
	FILE *file;
	int c;
	file = fopen("a.txt","r");
	if(file == NULL) {
		printf("failtofopen\n");
		return;
	}

	while((c = fgetc(file)) != EOF) {
		printf("%c",c);
	
	}

	fclose(file);
}


// д�ļ� - c
void test02() {
	FILE *file;
	int i = 0;
	char word[100] = "";
	file = fopen("b.txt","w");
	
	fgets(word,sizeof(word),stdin);

	while(word[i] != '\0') {
		printf("%c",word[i] );
		fputc(word[i], file);
		i++;
	}

	

	fclose(file);
}

// д�ļ� - str
void test03() {
	FILE *file;
	int i = 0;
	char *words[] = {"��ǰ���¹�\n","��ǰ���¹�\n","��ǰ���¹�\n","��ǰ���¹�\n"};
	int num = sizeof(words) / sizeof(words[0]);
	file = fopen("c.txt","w");

	for(i = 0 ; i < num ; i++) {
		fputs(words[i],file);
	
	}
	


	fclose(file);
}

// ���ļ� - str
void test04() {
	FILE *file;
	int i = 0;
	char words[1024] = "";

	file = fopen("c.txt","r");

	while(fgets(words,sizeof(words), file)) {
		printf("%s", words);
	}
	fclose(file);
}

// д�ļ� - fwriter
void test05() {
	FILE *file;

	HERO heros[3] = {
		{1,"����",10},
		{2,"��˹",11},
		{1,"����",9},
	};
	file = fopen("heros.txt","w");

	fwrite(heros,sizeof(HERO),3,file);


	fclose(file);
}

// д�ļ� - fread
void test06() {
	int i = 0;
	FILE *file;

	HERO heros[3];
	file = fopen("heros.txt","r");

	fread(heros,sizeof(HERO),3,file);

	
	fclose(file);

	for(i = 0 ; i < 3 ; i++) {
		printf("%d\t", heros[i].id);
		printf("%s\t", heros[i].name);
		printf("%d\t", heros[i].age);
		printf("%\n");
	}
}


// д�ļ� - fprintf
void test07() {
	FILE *file;
	int i;
	HERO heros[3] = {
		{1,"����",10},
		{2,"��˹",11},
		{1,"����",9},
	};
	file = fopen("heros2.txt","w");

	for(i = 0 ; i < 3 ; i++) {
		fprintf(file,"ѧ��:%d ����:%s ����:%d\n",heros[i].id,heros[i].name,heros[i].age);
	}



	fclose(file);
}

// ���ļ� - fscanf
void test08() {
	FILE *file;
	int i;
	HERO heros[3];
	file = fopen("heros2.txt","r");

	for(i = 0 ; i < 3 ; i++) {
		fscanf(file,"ѧ��:%d ����:%s ����:%d\n",&heros[i].id,heros[i].name,&heros[i].age);
	}

	fclose(file);

	for(i = 0 ; i < 3 ; i++) {
		printf("%d\t", heros[i].id);
		printf("%s\t", heros[i].name);
		printf("%d\t", heros[i].age);
		printf("%\n");
	}
}

// ��ָ�븴λ - rewind

// �����ָ������ļ��ײ����ֽ��� - ftell����

// �ƶ��ļ�����ָ��λ��

// ���ļ�ȫ��������ص��ڴ��в����������̨
void test09() {
	FILE *file = NULL;
	char *chapter;
	long len;
	file = fopen("x.txt","r");
	if(file == NULL) {
		perror("fopen");
		return;
	}
	fseek(file,0,2);
	len = ftell(file);
	// ��λָ��
	rewind(file);
	// 1. ��̬����ռ�
	chapter = (char *)calloc(1,len + 1);
	// һ���Խ��ļ����� ���뵽 �ڴ�ռ�
	fread(chapter,len,1,file);
	printf("%s\n",chapter);
	fclose(file);

};

int main() {
	test09();
	return 0;
}