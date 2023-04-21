 // test to show implicit type casting
 class test4 {
    public static int main(String args[]) {
      int myInt = 9;
      double myDouble = myInt; // Automatic casting: int to double
      float y = 4.0;
      myDouble = myInt + y;
      
      System.out.println(myInt);      // Outputs 9
      System.out.println(myDouble);   // Outputs 9.0
      return myInt;
    }
  }
  