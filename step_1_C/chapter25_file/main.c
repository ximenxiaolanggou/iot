#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int id;
	char name[100];
	int age;
}HERO;

// 读取文件 - c
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


// 写文件 - c
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

// 写文件 - str
void test03() {
	FILE *file;
	int i = 0;
	char *words[] = {"窗前明月光\n","窗前明月光\n","窗前明月光\n","窗前明月光\n"};
	int num = sizeof(words) / sizeof(words[0]);
	file = fopen("c.txt","w");

	for(i = 0 ; i < num ; i++) {
		fputs(words[i],file);
	
	}
	


	fclose(file);
}

// 读文件 - str
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

// 写文件 - fwriter
void test05() {
	FILE *file;

	HERO heros[3] = {
		{1,"张三",10},
		{2,"里斯",11},
		{1,"王五",9},
	};
	file = fopen("heros.txt","w");

	fwrite(heros,sizeof(HERO),3,file);


	fclose(file);
}

// 写文件 - fread
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


// 写文件 - fprintf
void test07() {
	FILE *file;
	int i;
	HERO heros[3] = {
		{1,"张三",10},
		{2,"里斯",11},
		{1,"王五",9},
	};
	file = fopen("heros2.txt","w");

	for(i = 0 ; i < 3 ; i++) {
		fprintf(file,"学号:%d 姓名:%s 年龄:%d\n",heros[i].id,heros[i].name,heros[i].age);
	}



	fclose(file);
}

// 读文件 - fscanf
void test08() {
	FILE *file;
	int i;
	HERO heros[3];
	file = fopen("heros2.txt","r");

	for(i = 0 ; i < 3 ; i++) {
		fscanf(file,"学号:%d 姓名:%s 年龄:%d\n",&heros[i].id,heros[i].name,&heros[i].age);
	}

	fclose(file);

	for(i = 0 ; i < 3 ; i++) {
		printf("%d\t", heros[i].id);
		printf("%s\t", heros[i].name);
		printf("%d\t", heros[i].age);
		printf("%\n");
	}
}

// 流指针复位 - rewind

// 获得流指针距离文件首部的字节数 - ftell函数

// 移动文件的流指针位置

// 将文件全部输入加载到内存中并输出到控制台
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
	// 复位指针
	rewind(file);
	// 1. 动态分配空间
	chapter = (char *)calloc(1,len + 1);
	// 一次性将文件数据 读入到 内存空间
	fread(chapter,len,1,file);
	printf("%s\n",chapter);
	fclose(file);

};

int main() {
	test09();
	return 0;
}