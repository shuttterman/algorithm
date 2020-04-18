#include <cstdio>

void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}


class selectionSort {
    private:
        int comparison_count;
    public:
        selectionSort(){comparison_count = 0;}
        void print_cc(){printf("%d", comparison_count);}
        void Sort(int *A, int n) {
            for(int i=n ; i>0 ; i--) {
                int last = 0;
                for(int j=1 ; j<i ; j++) {
                    if(A[j]>A[last]) {
                        last = j;
                        comparison_count++;
                    }
                }
                swap(A[i-1], A[last]);
            }
        }
};
int main() {
    selectionSort ss;
    int size;
    scanf("%d", &size);
    int *array = new int[size];
    for(int i=0 ; i<size ; i++)scanf("%d", array+i);
    ss.Sort(array, size);
    ss.print_cc();
    return 0;
}
