public class test7 {
    void main()
    {
      int a[][] = new int [5][4];
      for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
          a[i][j] = a[i][j] + a[i-1][j-1];
        }
      }
    }
}