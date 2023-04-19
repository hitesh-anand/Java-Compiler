#include<stdio.h>

int fib(int a[]) {
	a[0] = 1 +a[1];
}

int main()
{
	int a[] = {1,2,3,4};
	fib(a);
	return 0;
}
