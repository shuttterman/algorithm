#include <cstdio>
void swap(int& a, int& b) {
    int t=a;
    a=b;
    b=t;
}
class BubbleSort {
    private:
        int count;
    public:
        BubbleSort(){count=0;}
        void print_count(){printf("%d", count);}
        void Sort(int* arr, int n) {
            for(int i=n-1 ; i>0 ; i--) {
                for(int j=0 ; j<i ; j++) {
                   if(arr[j]>arr[j+1]) {
                      swap(arr[j], arr[j+1]);
                      count++;
                   }
                }
            }
        }
};

int main(){
    BubbleSort bs;

    int size;
    scanf("%d", &size);
    int *array = new int[size];
    for(int i=0 ; i<size ; i++)scanf("%d", array+i);
    bs.Sort(array, size);
    bs.print_count();

    return 0;
} 
