public class MyClass {
    
    // int a[] = new int [4];
       // function to check if a given string is a palindrome
    public static void add(int a, int b, int c[], int d, int e, int f, int g)
    {
        int cc = a + b + c[1] + d + e + f + g ;
        System.out.println(cc);
    }

    public static void main(String args[]) {
        int c[] = new int[5];
        c[1] = 2;
        add(1,2,c,4,5,6,7);
    }
}
