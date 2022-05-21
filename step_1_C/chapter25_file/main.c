#include<stdio.h>

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


int main() {
	test04();
}