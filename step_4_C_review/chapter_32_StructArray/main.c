#include<stdio.h>

struct stu{
	int num;
	char name[20];
	char sex;
};
int main()
{
    struct stu persons[3] = {
        {11, "lisi", 'A'},
        {12, "wangwu", 'B'},
        {13, "zhaol", 'B'}
    };

    for (int i = 0; i < 3; i++)
    {
        struct stu person = persons[i];
        printf("num:%d,name:%s,sex:%c\n", person.num, person.name, person.sex);
    }
}