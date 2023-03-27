//test for if,while and for loops and also class extends 
//to check for basic arithmetic operations
class hello {
    int f(int a, int b) {
        while (a < b) {
            int c = 0;
            if (a > 0)
                for (int i = 0; i < 10; ++i)
                    while (i < 10) {
                        int y;
                        c = c + 1;
                    }
            else
                c = a - 1;
            a = a + 1;
        }
        return a++;
    }
}

class hi extends hello {
    int T(int a, int b) {
        f(a,b);
        int w=a/b;
        w++;
        //w=++w+w++;
        int z=w==2?w++:++w;
        int ans=1;
        ans/=z;
        return ans;
    }
}
