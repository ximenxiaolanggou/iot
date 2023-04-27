#include<stdio.h>
#include<stdlib.h>


// 打开文件

void openFile()
{
    FILE *fp;
    //以只读的方式打开文件，如果文件不存在则报错
    //fp = fopen("d:/test.txt","r");

    //以只写的方式打开文件，如果文件不存在则创建，如果文件存在清空
    //fp = fopen("d:/test.txt", "w");

    //以只写的方式打开文件，如果文件不存在则创建，入股哦文件存在则追加
    fp = fopen("d:/test.txt", "a");

    if(fp == NULL)
    {
        printf("fail to fopen\n");
        return;
    }

    //使用fclose关闭文件
    fclose(fp);
}

// 读一个字符
void fgetC()
{
    FILE *fp;

    fp = fopen("d:/test.txt", "r");

    if(fp == NULL)
    {
        printf("fail to fopen\n");
        return;
    }

    //文件的每一行结束的位置都有一个标识，是一个换行符，称之为行结束符
    //fgetc可以读取到行结束符
    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }

    printf("\n");
    

    //使用fclose关闭文件
    fclose(fp);
}

// 写一个字符
void fputC()
{
    FILE *fp;

    char *words = "hellow java";

    fp = fopen("d:/test_copt.txt", "w");

    if(fp == NULL)
    {
        printf("fail to fopen\n");
        return;
    }

    while (*words != '\0')
    {
        fputc(*words, fp);
        words ++;
    }
    

    fclose(fp);
}


// 读取一行
void fgetS()
{
     FILE *fp;

    fp = fopen("d:/test.txt", "r");

    if(fp == NULL)
    {
        printf("fail to fopen\n");
        return;
    }

   
    char buf[32];

    fgets(buf, 32, fp);
    printf("%s", buf);

    fgets(buf, 32, fp);
    printf("%s", buf);
    

    //使用fclose关闭文件
    fclose(fp);
}

// 写一行字符串
void fputS()
{
    FILE *fp;

    char *words = "hellow java scala";

    fp = fopen("d:/test_copt_2.txt", "w");

    if(fp == NULL)
    {
        printf("fail to fopen\n");
        return;
    }

    fputs(words, fp);
    

    fclose(fp);
}

// 读文件
void fRead()
{
    printf("+++++++++++++++++++++\n");
    FILE *fp;

    fp = fopen("d:/test.txt", "r");

    if(fp == NULL)
    {
        printf("fail to fopen\n");
        return;
    }

    int num;
    char buf[32];
    num = fread(buf, 5, 4, fp);

    printf("buf = %s\n", buf);
    printf("num = %d\n", num);

    //使用fclose关闭文件
    fclose(fp);
}

struct stu
{
    char name[12];
    int age;
};


void fWrite()
{
    printf("+++++++++++++++++++++\n");
    struct stu stus[2] = {
        {"zhangsan", 12},
        {"lisi", 13}
    };

    FILE *fp;
    fp = fopen("d:/test_copt_3.txt", "w+");

    fwrite(stus, sizeof(struct stu), 2, fp);

    //将文件的偏移量设置为文件的起始位置
    rewind(fp);

    struct stu stusBak[2];

    fread(stusBak, sizeof(struct stu), 2, fp);

    for (int i = 0; i < 2; i++)
    {
        struct stu s = stusBak[i];

        printf("name:%s,age:%d\n", s.name, s.age);
    }
    

    fclose(fp);

}


// 格式化保存和读取数据

void formatRW()
{
    FILE *fp;
    char ch1='a', ch2;
    int num1=50, num2;
    char string1[20]="hello", string2[20];
    float score1 = 85.5, score2;

    if((fp = fopen("d:/file.txt","w+"))==NULL)
    {
        printf("fail to fopen\n");
        return;
    }

    //使用fprintf向文件写入字符串
    fprintf(fp,"%c %d %s %f\n",ch1,num1,string1,score1);

    rewind(fp);
    //使用fscanf获取文件内容
    fscanf(fp,"%c %d %s %f\n",&ch2,&num2,&string2,&score2);
    printf("%c %d %s %f\n",ch2,num2,string2,score2);

    fclose(fp); return 0;

}

int main()
{
    openFile();
    fgetC();
    fputC();
    fgetS();
    fputS();
    fRead();
    fWrite();
    formatRW();
    return 0;
}