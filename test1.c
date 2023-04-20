#include<stdio.h>	
int r(int r,int a[],int b[],int c[],int d[],int e[],int f[]){
    a[3]=2;
}
int main() {	
    int c[10]={1,2,3,4,5,6,7,8,9,0};
    r(c[0],c,c,c,c,c,c);
}