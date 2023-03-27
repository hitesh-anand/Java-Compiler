//multidimensional array
public class test5 {
    public int sum(int a[][]){
        int ans=0;
        for(int i=0;i<30;i++)
            for(int j=0;j<30;++j){
                ans+=a[i][j];
            }
        
        return ans;
    }
    public int main(){
        int arr[][]=new int [30][30];
        for(int i=0;i<30;i++)
            for(int j=0;j<30;++j){
                arr[i][j]=i*j;
            }
        int u=sum(arr);
        if(++u>5){
            return u--;
        }
        else if(u++<4){
            return --u;
        }
        else if(u==10){
            return u+4;
        }
        else{
            return arr[0][0];
        }
        return 0;
    }
}
