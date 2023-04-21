//test for static variables and functions

class test9{
    static int count=0;
    test9(int a)
    {
        count = a;
    }
    public void func1(int a)
    {
        a = 2;
        if(a==1)
            a+=3;
    }

    public static int call(int b, int c)
    {
        int sum = b+c;
        int diff = b-c;
        if(b>0)
            return sum;
        return diff;
    }
}

class test{
    void func2(int a)
    {
        test9.count++;
        test9 ob = new test9(a);
        ob.func1(a);
        test9.call(a, a+1);
    }
}