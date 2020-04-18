#include <cstdio>
void swap(int& a, int& b) {
    int t=a;
    a=b;
    b=t;
}
 
int ceil(double t) {
    if(t==(int)t)return t;
    else return t+1;
}
 
class LinearSelect {
    public:
        int select(int* arr, int p, int r, int i) { 
            if(p==r) return arr[p];
            int q = partition(arr, p, r);
            int k = q - p + 1;
            if(i<k) return select(arr, p, q-1, i);
            else if(i>k) return select(arr, q+1, r, i-k);
            else return arr[q];
        }
 
        int partition(int* arr, int p, int r) {
            int x = arr[r];
            int i = p-1;
            for(int j=p ; j<r ; j++)
                if(arr[j] <= x) swap(arr[++i], arr[j]);
            swap(arr[i+1], arr[r]);
            return i+1;
        }
         
        int linearselect(int* arr, int p, int r, int i) {
            int j=0;
            double n = r-p+1; 
            if(n<=5)return select(arr, p, r, i);
            else {
                double t=ceil(n/5);
                int* brr = new int[ceil(n/5)];
                for(int i=p ; i<=r ; i+=5, j++) {
                    if(r-i > 3) brr[j] = select(arr, i, i+4, 3);
                    else brr[j] = select(arr, i, r, ((r-i)/2)+1);
                }
                int m = linearselect(brr, 0, t-1, ceil(t/2));
                printf("%d\n", m);
                int q = partitionByMedian(arr, p, r, m);
                int k = q - p + 1;
                if(i<k) return linearselect(arr, p, q-1, i);
                else if(i>k) return linearselect(arr, q+1, r, i-k);
                else return arr[q];
            }
        }   
        int partitionByMedian(int* arr, int p, int r, int m) {
            int i;
            for(i=p ; i<=r ; i++)
                if(arr[i]==m)break;
            swap(arr[i], arr[r]);
            return partition(arr, p, r);
        }
 
 
};
 
int main() {
    LinearSelect ls;
    int arr_size;
    scanf("%d", &arr_size);
    int* array = new int[arr_size];
 
    int numb;
    scanf("%d", &numb);
 
    for(int i=0 ; i<arr_size ; i++)scanf("%d", array+i);
    ls.linearselect(array, 0, arr_size-1, numb);
    return 0;
}

