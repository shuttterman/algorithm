#include <cstdio>


class Graph {
    private :
        int** arr;
        int* Q;
        int qsize;
        int* d;
        int* tree;
        int size;
    public :
        Graph(int size) {
            this->arr = new int*[size];
            for(int i=0 ; i<size ; i++)this->arr[i]=new int[size];
            for(int i=0 ; i<size ; i++) 
                for(int j=0 ; j<size ; j++) 
                    this->arr[i][j] = 0;
            this->Q = new int[size];
            for(int i=0 ; i<size ; i++)this->Q[i] = 1;
            this->size = size;
            this->qsize = size;
            this->d = new int[size];
            this->tree = new int[size];
        }
        void add_edge(int x, int y, int w) {
            this->arr[x][y] = w;
            this->arr[y][x] = w;
        }

        void prim(int r) {
            int sum=0;
            for(int i=0 ; i<size ; i++) {
                d[i] = 99999;
                tree[i] = 0;
            }
            d[r] = 0;
            while(qsize != 0 ) {
                int u = extract_min();
                for(int i=0 ; i<size ; i++) {
                    if(arr[u][i]>0) {
                        if((Q[i]==1)&&(arr[u][i] < d[i]))
                            d[i] = arr[u][i];
                            tree[i] = u;
                    }
                }
            }
            for(int i=0 ; i<size ; i++)sum+=d[i];
            printf("%d", sum);
        }

        int extract_min() {
            int min=99999;
            int temp;
            for(int i=0 ; i<size ; i++) {
                if(Q[i]==1) {
                    if(d[i] < min) {
                        temp = i;
                        min = d[i];
                    }
                }
            }
            Q[temp] = 0;
            qsize--;
            printf("%d ", temp+1);
            return temp;
        }


};
int main() {

    int size, count;
    int x, y, w;
    scanf("%d", &size);
    Graph graph(size);
    scanf("%d", &count);
    for(int i=0 ; i<count ; i++) {
        scanf("%d %d %d", &x, &y, &w);
        graph.add_edge(x-1, y-1, w);
    }
    graph.prim(0);

    return 0;
}
