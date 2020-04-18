#include <cstdio>
int max_arr(int* arr,int n){
    int tmp;
    tmp = arr[0];
    for(int i=1 ; i<n ; i++)
        if(arr[i]>tmp)tmp=arr[i];
    return tmp;
}
int min_arr(int* arr, int n) {
    int tmp;
    tmp = arr[0];
    for(int i=1 ; i<n ; i++)
        if(arr[i]<tmp)tmp=arr[i];
    return tmp;
}
class CountingSort{
    private:
        int count;
    public:
        CountingSort(){count=0;}
        void print_count(){printf("%d", count);}
        void Sort(int* a, int* b, int n) {
            int max = max_arr(a,n);
            int min = min_arr(a,n);
            int i;
            int k = max-min+1;
            int* c = new int[k];
            for(i=0 ; i<k ; i++)c[i]=0;
            for(i=0 ; i<n ; i++)c[a[i]-min]++;
            for(i=1 ; i<k ; i++)c[i] = c[i] + c[i-1];
            for(i=0 ; i<k ; i++)printf("%d ", c[i]);
            for(i=n-1 ; i>=0 ; i--) {
                b[c[a[i]-min]-1] = a[i];
                c[a[i]-min]--;
            }
        }
};

int main(){
    CountingSort cs;

    int size;
    scanf("%d", &size);
    int* arra = new int[size];
    int* arrb = new int[size];
    for(int i=0 ; i<size ; i++)scanf("%d", arra+i);
    cs.Sort(arra,arrb,size);
    
    return 0;
}

