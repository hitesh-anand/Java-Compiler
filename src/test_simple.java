//simple test for function-calls, object creation
class hello {
    int c;
    hello(int a, int b)
    {
        c = a;
    }
    int f(int a, int b) {
        // int c=2;
        if(a==1)
        {
            b++;
            int c = 1;
        }
        return a++;
    }
}

class hi{
    int T(int a, int b) {
        int n = a+b;
        int k = a-b;
        hello h = new hello(n, k);
        return h.f(n, k);
        // return 1;
    }
    public static void main(String args[]){
        int y=T(1,2);
        System.out.println(y);
    }
}
