// to show 1 d array usage and initialization
class NumberToWordExample1 {

    static void func() {
        int len=5;
        if (len == 0) {

            System.out.println("The string is empty.");
            return;
        }

        if (len > 4) {

            System.out.println("\n The given number has more than 4 digits.");
            return;
        }

        int onedigit[] = new int[] { 1,2,4,5,6};


        System.out.println(": ");

        if (len == 1) {
            System.out.println(1);
            onedigit[1]=5;
            return;
        }
        int x = 0;
        return ;
    }
    static void func2() {
        int len=5;
        if (len == 0) {

            System.out.println("The string is empty.");
            return;
        }

        if (len > 4) {

            System.out.println("\n The given number has more than 4 digits.");
            return;
        }

        int twodigit[][] = new int[][] { {1,2,4,5,6},{44,2,43,4,5}};


        System.out.println(": ");

        if (len == 1) {
            System.out.println(1);
            twodigit[1][1]=5;
            return;
        }
        return ;
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