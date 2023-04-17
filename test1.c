#include<stdio.h>   
void printName(int a[])  
{  
	a[0]=1;
	printName(a);
	return;
}  
void main ()  
{  
	int b = 7;
	int c = 8;
	int a[5]={1,2,3,4,5};
	printName(a);
	return;
}  
