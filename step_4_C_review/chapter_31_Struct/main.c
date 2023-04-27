#include<stdio.h>
#include<string.h>

// 定义结构体
struct stu
{
   char name[20];
   int age;
   char sex;
}zhangsan, lisi = {"lisi", 12, '男'};


//如果使用typedef对结构体类型取别名
//就无法在定义类型的同时定义结构体变量
//在定义结构体变量的时候不用加struct
typedef struct
{
   char name[20];
   int age;
   char sex;
}STU;

typedef struct 
{
    int year;
    int month;
    int day;
}BD;

typedef struct
{
    char name[20];
    BD birthday;
}PER;




int main()
{
    struct stu wangwu = {"wangwu", 13, 'A'};

    STU zhaoliu = {"zhaoliu", 13, 'B'};

    strcpy(wangwu.name, "wangwu555");


    printf("name:%s,age:%d,sex:%c\n",wangwu.name, wangwu.age, wangwu.sex);

    PER person1;
    //如果结构体中嵌套结构体，赋值时找到最内层的成员再进行赋值
    strcpy(person1.name, "person");
    person1.birthday.year = 2021;
    person1.birthday.month = 10;
    person1.birthday.day = 10;
   
    printf("name:%s,year:%d\n",person1.name, person1.birthday.year);

    // 相同类型的结构体变量可以相互赋值

    struct stu stu1 = {"stu1", 13, 'A'};
    struct stu stu2;
    stu2 = stu1;
    printf("name:%s,age:%d,sex:%c\n",stu2.name, stu2.age, stu2.sex);
}