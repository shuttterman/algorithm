#include <cstdio>
int max(int a, int b) {
    return (a>b)?a:b;
}
int max(int a, int b, int c) {
    return (((a>b)?a:b)>c)?((a>b)?a:b):c;
}
void peb(int** arr, int j, int p) {
    switch(p) {
        case 0 :
            arr[p][j] = max(arr[1][j-1], arr[2][j-1]) + arr[p][j];
            break;
        case 1:
            arr[p][j] = max(arr[0][j-1], arr[2][j-1], arr[3][j-1]) + arr[p][j];
            break;
        case 2:
            arr[p][j] = max(arr[0][j-1], arr[1][j-1]) + arr[p][j];
            break;
        case 3:
            arr[p][j] = arr[1][j-1] + arr[p][j];
            break;
        default :
            printf("error");
            break;
    }
}

int main() {
    int n,t=0;
    scanf("%d", &n);
    int* arr[4]; 
    for(int i=0 ; i<4 ; i++)arr[i] = new int[n];

    for(int i=0 ; i<3 ; i++) 
        for(int j=0 ; j<n ; j++) 
            scanf("%d", &arr[i][j]);
    for(int j=0 ; j<n ; j++)arr[3][j]=arr[0][j]+arr[2][j];
    for(int j=1 ; j<n ; j++) {
        for(int i=0 ; i<4 ; i++) {
            peb(arr, j, i);
        }
    }
    for(int i=0 ; i<4 ; i++) {
        if(t<arr[i][n-1])t=arr[i][n-1];
    }
    printf("%d", t);

    

    return 0;
}
