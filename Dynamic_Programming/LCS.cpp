#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int max(int x, int y) {
    return (x>y) ? x:y;
}

int main() {
    string str1,str2;
    cin >> str1;
    cin >> str2;

    int** mat = new int*[str1.length()+1];
    for(int i=0 ; i<=str1.length() ; i++)mat[i] = new int[str2.length()+1];

    for(int i=0 ; i<=str1.length() ; i++)mat[i][0]=0;
    for(int i=0 ; i<=str2.length() ; i++)mat[0][i]=0;

    for(int i=1 ; i<=str1.length() ; i++) {
        for(int j=1 ; j<=str2.length() ; j++) {
           if(str1[i-1] == str2[j-1]) mat[i][j] = mat[i-1][j-1] + 1;
           else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }
    }
    for(int i=0 ;  i<str1.length()+1 ; i++) {
        for(int j=0 ; j<str2.length()+1 ; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("%d", mat[str1.length()][str2.length()]);

    return 0;
}
