#include<stdio.h>

int fib(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	return fib(n-1) + fib(n-2);
}

int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int x=4;
	int y=3;
	a[x]=10;
	int b[3][5]={{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
	b[2][3]=5;
	return 0;
}
