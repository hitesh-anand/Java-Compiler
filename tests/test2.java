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
                    }
            else
                c = a - 1;
            a = a + 1;
        }
        return a++;
    }
}
