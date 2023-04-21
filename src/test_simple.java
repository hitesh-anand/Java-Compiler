//simple test for function-calls, object creation
class hello {
    int c;
    hello(int a, int b)
    {
        c = a;
    }
    int f() {
        int b=2, a;
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
        h.f();
        return 1;
    }
    public static void main(String args[]){
        int y=T(1,2);
        System.out.println(y);
    }
}
