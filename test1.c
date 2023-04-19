#include<stdio.h>

int fib(int a[]) {
	a[0] = 1 +a[1];
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
