#include<stdio.h>

void compare();
void sub();
void assignment();
int main()
{

    compare();
    sub();
    assignment();
    return 1;
}

void sub()
{
    int arr[10];

    int *p = &arr[2];
    int *q = &arr[5];

    printf("%d\n", q - p);
}

void assignment()
{
    int a = 1;

    int *p, *q;

    p = &a;

    q = p;

    *q = 2;

    printf("a=%d, *p=%d\n", a, *p);
}


void compare()
{
    int arr[10];

    int *p = &arr[2];
    int *q = &arr[5];

    if(p > q)
    {
        printf("p>q\n");
    }else
    {
        printf("p<q\n");
    }
}