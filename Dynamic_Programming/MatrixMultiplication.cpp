#include <cstdio>
int min(int x, int y) {
    return (x>y) ? y:x;
}
class matrix {
    public:
        int r;
        int c;
};


int main() {
    int n,j;
    scanf("%d", &n);
    matrix* mat = new matrix[n];

    for(int i=0 ; i<n ; i++) 
        scanf("%d %d", &(mat[i].r), &(mat[i].c));

    int** arr = new int*[n];
    for(int i=0 ; i<n ; i++)arr[i] = new int[n];
    for(int i=0 ; i<n ; i++)arr[i][i]=0;

    for(int d=1 ; d<n ; d++) {
        for(int i=0 ; i<n-d ; i++) {
            j=i+d;
            arr[i][j] = 9999999;
            for(int k=i ; k<=j-1 ; k++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k+1][j] + (mat[i].r * mat[k].c * mat[j]. c));
            }
        }
 
    }
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
