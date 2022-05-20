#include<stdio.h>

int sum(int a, int b) {
	return a + b;
}

int divide(int a, int b) {
	return a - b;
}

int action(int a, int b, int (*fun)(int,int)) {

	return fun(a,b);
}


int main() {
  int a = 1;
  int b = 2;

  printf("%d\n",action(a,b,sum));
  printf("%d\n",action(a,b,divide));

}