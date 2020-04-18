#include <cstdio>
void swap(int& a, int& b) {
    int t=a;
    a=b;
    b=t;
}
class HeapSort{
    private:
        int count;
    public:
        HeapSort(){count=0;}
        void print_count(){printf("%d", count);}
        void Sort(int* arr, int n) {
            buildHeap(arr, n);
            for(int i=n ; i>1 ; i--) {
                swap(arr[1], arr[i]);
                heapify(arr, 1, i-1);
            }
        }
        void buildHeap(int* arr, int n) {
            for(int i=n/2 ; i>0 ; i--)heapify(arr, i, n);
            count=0;
        }
        void heapify(int* arr, int k, int n) {
            int left=2*k;
            int right=2*k+1;
            int bigger; 
            if(right<=n) {
                if(arr[left]>arr[right])bigger=left;
                else bigger=right;
            }
            else if(left<=n)bigger=left;
            else return;

            if(arr[bigger] > arr[k]) {
                swap(arr[k], arr[bigger]);
                count++;
                heapify(arr, bigger, n);
            }
        }
};

int main() {
    HeapSort hs;
    int size;
    scanf("%d", &size);
    int* array = new int[size+1];
    for(int i=1 ; i<=size ; i++)scanf("%d", array+i);
    hs.Sort(array, size);
    hs.print_count();
    return 0;
}
