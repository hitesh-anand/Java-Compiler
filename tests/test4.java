 // to show implicit type casting
 class ftd {
    public static int main(String args[]) {
      int myInt = 9;
      double myDouble = myInt; // Automatic casting: int to double
      // float y = 4.0;
      // myDouble = myInt + y;
      boolean test = (float) myDouble;
      System.out.println(myInt);      // Outputs 9
      System.out.println(myDouble);   // Outputs 9.0
      return myInt;
    }
  }
  //  class dtf {
  //   public static void main2(String[] args) {
  //     double myDouble = 9.78d;
  //     System.out.println(myDouble);   // Outputs 9.78
  //   }
  // }
  