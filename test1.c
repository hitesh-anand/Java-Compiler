#include<stdio.h>	


int fib(int n)
{
    if(n <= 1) return 1;
    else {
        return fib(n-1) + n;
    }
}
int main()
{
    int n = 9;
    int x = fib(14);
    printf("%d\n", x);
}