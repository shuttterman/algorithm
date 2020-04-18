#include <cstdio>

class InsertionSort{
    private:
        int count;
    public:
        InsertionSort(){count=0;}
        void print_count(){printf("%d", count);}
        void Sort(int* a, int n) {
            for(int i=1 ; i<n ; i++) {
                int loc=i-1;
                int Item=a[i];
                while(loc>=0 && Item < a[loc]) {
                    a[loc+1] = a[loc];
                    loc--;
                    count++;
                }
                a[loc+1] = Item;
                count++;
            }
        }
};



int main() {
    InsertionSort is;
    int size;
    scanf("%d", &size);
    int* array = new int[size]; 
    for(int i=0 ; i<size ; i++)scanf("%d", array+i);
    is.Sort(array, size);
    is.print_count(); 

    return 0;
}
