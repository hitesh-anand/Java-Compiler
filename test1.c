#include<stdio.h>	

int* getarray()
{
    int a[] = {1,2,3,4};
    return a;
}


int main()
{
    int nums[] = getarray();
}