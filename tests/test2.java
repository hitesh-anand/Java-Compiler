//Test for for/while loops and if-else

class test2 {
    int f(int a, int b) {
        while (a < b) {
            int c = 0;
            if (a > 0)
                for (int i = 0; i < 10; ++i)
                    while (i < 10) {
                        int y=1;
                        c = c + 1;
                        i++;
                    }
            else
                c = a - 1;
            a = a + 1;
        }
        return a++;
    }
    public static void main(String args[]){
        test2 t = new test2();
        int y=t.f(1,2);
        System.out.println(y);
    }
}
