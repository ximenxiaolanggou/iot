#include<stdio.h>

extern void print(void);
extern int data;
int main(){

	print();
}

int data = 100;