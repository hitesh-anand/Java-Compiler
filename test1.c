#include<stdio.h>   
void printName(int a[],int b,int c,int d,int e,int f,int g,int h)  
{  
	a[0]=1;
	printName(a,b,c,b,b,b,g,h);
	return;
}  
void main ()  
{  
	int b = 7;
	int c = 8;
	int a[5]={1,2,3,4,5};
	printName(a,b,c,b,b,b,b,b);
	return;
}  
