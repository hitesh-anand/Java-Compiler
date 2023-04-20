#include<stdio.h>	
	int main() {	
		int i;
        int n = 10;
        int c[10];
        int x;
        for(i = 0; i < n; i++) {
            c[i] = i + 1;   
            x = c[i] + 0;
            printf("%d\n", x);
        }
        x = c[2] + c[3];
        printf("%d\n", x);
	}