class DoWhileExample {    
  public int main() {    
      int i=1;    
      do{    
          System.out.println(i); 
          int j=0;
          do{
            j++;
          } 
          while(j<5);  
          i++;    
      }while(i<=10);    
      return 1;
  }    
}