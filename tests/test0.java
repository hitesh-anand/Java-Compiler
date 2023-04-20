public class MyClass {
    
    // int a[] = new int [4];
       // function to check if a given string is a palindrome
    public void add(int a[])
    {
        int c = a[0]+a[1];
        System.out.println(c);
    }

    public static void main(String args[]) {
    
        int a[] = new int [5];
        int i;
        //System.out.println();
        for(i = 0; i < 4; i++) {
            a[i] = i +1 ;
            int x = a[i];
            System.out.println(x);
        }
        int x = 1;
        add(a);;
       
        
    }
}
