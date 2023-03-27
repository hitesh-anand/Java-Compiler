public class test8 {
    int quick_sort(int arr[], int left, int right) {
        int comp = 0;
        if (left < right) {
            int pivot = arr[right];
            int i = left;
            int j = left;
            while (i < right) {
                comp++;
                if (arr[i] <= pivot) {
                    int t=arr[i];
                    arr[i]=arr[j];
                    arr[j]=t;
                    j++;
                }
                i++;
            }
            int t=arr[j];
            arr[j]=arr[right];
            arr[right]=t;
            comp += quick_sort(arr, left, j - 1);
            comp += quick_sort(arr, j + 1, right);
        }
        return comp;
    }
    int main() {
        int n;
        int arr[] = { 4, 5, 3, 7, 3, 2, 1, 6, 8, 9 };
        n = 10;
        quick_sort(arr, 0, n - 1);
        return 0;
    }
}
