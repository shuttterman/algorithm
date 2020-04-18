#include <cstdio>
#include <queue>
using namespace std;
int digit(int a, int n) {
    for(int i=0 ; i<n-1; i++)a/=10;
    return a%10;
}
int max_digit(int a) {
    int count=0;
    while(a!=0) {
        a/=10;
        count++;
    }
    return count;
}
class RadixSort {
    public:
        int t;
        RadixSort(){}
        queue<int> Q[10];
        void Sort(int* arr, int n, int k) {
           for(int i=0 ; i<t ; i++) {
              for(int j=0 ; j<n ; j++) {
                  int d=digit(arr[j], i+1);
                  Q[d].push(arr[j]);
              }
              int p=0; 
              for(int j=0 ; j<10 ; j++)
                  while(!Q[j].empty()) {
                      arr[p++] = Q[j].front();
                      Q[j].pop();
                  }
           }
        }
};

int main(){
    RadixSort rs;
    
    int size;
    scanf("%d", &size);
    int* array = new int[size];
    scanf("%d", &rs.t);
    for(int i=0 ; i<size ; i++)scanf("%d", array+i);
    int tmp = array[0];
    for(int i=1 ; i<size ; i++)
        if(tmp<array[i])tmp=array[i];
    rs.Sort(array, size, max_digit(tmp));
    for(int i=0 ; i<size ; i++)printf("%d ", *(array+i));
    
    return 0;
}
