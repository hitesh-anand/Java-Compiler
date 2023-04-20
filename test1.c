#include<stdio.h>	
#include<stdlib.h>

int* getarray()
{
    int * a = malloc(5*sizeof(int));
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 1;
    return a;
}


int main()
{
    int* nums = getarray();
}