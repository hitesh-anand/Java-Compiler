//simple test for function-calls, object creation
class hello {
    int c;
    int f(int a, int b) {
        // int c=2;
        if(a==1)
        {
            b++;
            // int c = 1;
        }
        return a++;
    }
}

class hi{
    int T(int a, int b) {
        int n = a+b;
        int k = a-b;
        hello h = new hello();
        int kk = h.f(n, k);
        return kk;
    }
    void main(){
        int y=T(1,0);
        System.out.println(y);
    }
}