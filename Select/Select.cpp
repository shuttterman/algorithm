#include <cstdio>
void swap(int& a, int& b) {
    int t=a;
    a=b;
    b=t;
}
class Select {
    private:
        int count;
    public:
        Select(){count=0;}
        void print_count(){printf("%d", count);}
        int select(int* arr, int p, int r, int i) {
            if(p==r)return arr[p];
            int q = partition(arr, p, r);
            int k = q - p + 1;
            if(i<k) return select(arr, p, q-1, i);
            else if(i>k) return select(arr, q+1, r, i-k); 
            else return arr[q];
        }
        int partition(int* arr, int p, int r) {
            int x = arr[r];
            int i = p-1;
            for(int j=p ; j<r ; j++) {
                if(arr[j] <= x) {
                    swap(arr[++i], arr[j]);
                    count++;
                }
            }
            swap(arr[i+1], arr[r]);
            count++;
            return i+1;
        }
};

int main() {
    Select s;

    int arr_size;
    scanf("%d", &arr_size);
    int* arr = new int[arr_size];

    int number_b;
    scanf("%d", &number_b);
    
    for(int i=0 ; i<arr_size ; i++)scanf("%d", arr+i);
    s.select(arr, 0, arr_size-1, number_b);

    s.print_count(); 
    return 0;
}
