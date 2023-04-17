// to show 1 d array usage and initialization
class NumberToWordExample1 {
    static void help(int a[],int c){
        a[0]=1;
        a[1]=2;
        a[2]=3;
        a[3]=4;
        a[4]=5;
        a[5]=6;
        a[6]=7;
        a[7]=8;
        a[8]=9;
        a[9]=10;
    }
    static void help2(int b[][]){

    }
    static void func() {
        int onedigit[]=new int[10];
        int twodigit[][]=new int[10][10];
        help(onedigit,1);
        help2(twodigit);
    }

    // static void func3() {
    //     int len=5;
    //     int threedigit[][][] = new int[][][] { {{1,2,4,5,6},{44,2,43,4}},{{32,3,1}}};


    //     System.out.println(": ");

    //     if (len == 1) {
    //         System.out.println(1);
    //         threedigit[1][1][2]=5;
    //         return;
    //     }
    //     return ;
    // }

}