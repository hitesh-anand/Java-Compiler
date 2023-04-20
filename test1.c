#include<stdio.h>	
#include<stdlib.h>
    // int a[] = new int [4];
       // function to check if a given string is a palindrome
    void add(int* a)
    {
        int c = a[0]+a[1];
        printf("%d\n", c);
    }

    int main() {
    
        int *a = malloc(sizeof(int)*5);
        int i;
        //System.out.println();
        for(i = 0; i < 4; i++) {
            a[i] = i +1 ;
            int x = a[i];
            printf("%d\n", x);
        }
        
        add(a);
       
        
    }

