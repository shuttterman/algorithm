#include <cstdio>
int count;
bool isPrimeNumber(int x) {
    if(x>7) {
        if((x%3!=0)&&(x%5!=0)&&(x%7!=0))return true;
    }
    else {
        if((x==2)||(x==3)||(x==5)||(x==7))return true;
        else return false;
    }
    return false;
}
int hashf(int x, int m) {
    return x%m;
}
int hashif(int x, int m, int i) {
    return (hashf(x, m)+i) % m;
}

int main() {
    int n,m;
    int temp;
    scanf("%d", &n);
    m=n*2;
    for(int i=(m==2 ? 2: m+1);;i+=2) {
        if(isPrimeNumber(i)) {
            m=i;
            break;
        }
    }
    int* hashtable = new int[m];
    for(int i=0 ; i<n ; i++)hashtable[i]=0;
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &temp);
        if(hashtable[hashf(temp, m)]==0) {
            hashtable[hashf(temp, m)] = temp;
        }
        else {
            int j=0;
            while(hashtable[hashif(temp, m, j)] != 0) {
                count++;
                j++;
            }
            hashtable[hashif(temp, m ,j)] = temp;
        }
    }
    printf("%d",count);
    
    return 0;
}
