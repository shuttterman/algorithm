#include <cstdio>
void swap(int& a, int& b) {
    int t=a;
    a=b;
    b=t;
}
class QuickSort{
    private:
        int count;
    public:
        QuickSort(){count=0;}
        void print_count(){printf("%d", count);}
        void Sort(int* arr, int p, int r) {
            if(p<r) {
                int q=partition(arr, p, r);
                Sort(arr, p, q-1);
                Sort(arr, q+1, r);
            }
        }
        int partition(int* arr, int p, int r) {
             int x=arr[r];
             int i=p-1;
             for(int j=p ; j<r ; j++)
                 if(arr[j]<=x){swap(arr[++i], arr[j]);count++;}
             swap(arr[i+1], arr[r]);count++;
             return i+1; 
        }
};


int main(){
    QuickSort qs;
    int size;
    scanf("%d", &size);
    int* array = new int[size];
    for(int i=0 ; i<size ; i++)scanf("%d", array+i);
    qs.Sort(array, 0, size-1);
    qs.print_count();
    return 0;
}
