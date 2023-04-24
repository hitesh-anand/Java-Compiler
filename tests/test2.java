//Test for for/while loops and if-else

class test2 {
    int f(int a, int b) {
        while (a > b) {
            int c = 0;
            if (a > 0)
                a+=1;
            else
                c = a - 1;
            a = a + 1;
        }
        return a++;
    }
    public static void main(String args[]){
        test2 t = new test2();
<<<<<<< HEAD
        int y=t.f(1,5);
=======
        int y=t.f(1,2);
>>>>>>> c93454f3b5154ea4e6fe2417364a8e6eb5dd0cbf
        System.out.println(y);
    }
}
