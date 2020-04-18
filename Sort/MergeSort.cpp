#include <cstdio>

class mergeSort {
    private:
        int count;
    public:
        mergeSort(){count=0;}
        void print_count(){printf("%d", count);}
        void Sort(int* arr, int p, int r) {
            if(p<r) {
                int q=(p+r)/2;
                Sort(arr, p, q);
                Sort(arr, q+1, r);
                merge(arr, p, q, r);
            }
        }
        void merge(int* arr,int p,int q,int r) {
            int *tmp = new int[r+1];
            int i=p;
            int j=q+1;
            int t=0;
            while(i<=q && j<=r) {
                if(arr[i] >= arr[j]){tmp[t++]=arr[j++];}
                else {tmp[t++]=arr[i++];}
                count++;
            }
            while(i<=q)tmp[t++]=arr[i++];
            while(j<=r)tmp[t++]=arr[j++];
            i=p;
            t=0;
            while(i<=r)arr[i++]=tmp[t++];
            delete[] tmp;
        }
};

int main() {
    mergeSort ms;
    int size;
    scanf("%d", &size);
    int* array = new int[size];
    for(int i=0 ; i<size ; i++)scanf("%d", array+i);
    ms.Sort(array,0, size-1);
    ms.print_count();
    return 0;
}

