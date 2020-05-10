#include <cstdio>
int min(int x,int y) {
    return (x>y)?y:x;
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    int** mat = new int*[n];
    for(int i=0 ; i<n ; i++)mat[i] = new int[m];
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int** arr = new int*[n];
    for(int i=0 ; i<=n ; i++)arr[i]= new int[m];
    arr[0][0] = mat[0][0];
    for(int i=1 ; i<n ; i++)arr[0][i] = arr[0][i-1] + mat[0][i];
    for(int i=1 ; i<m ; i++)arr[i][0] = arr[i-1][0] + mat[i][0];
    for(int i=1 ; i<n ; i++) {
        for(int j=1 ; j<m ; j++) {
            arr[i][j] = min(arr[i-1][j], arr[i][j-1]) + mat[i][j];
        }
    }
    printf("%d", arr[n-1][m-1]);

    

    return 0;
}
