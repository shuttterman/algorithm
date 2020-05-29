#include <cstdio>
#include <cstring>
#define INF 99999
class Graph {
    private :
        int** arr;
        int size;
        int* d;
        int* prev;
        bool* S;
    public :
        Graph(int size) {
            this->size = size;
            arr = new int*[size];
            for(int i=0 ; i<size ; i++)arr[i] = new int[size];
            for(int i=0 ; i<size ; i++) 
                for(int j=0 ; j<size ; j++)arr[i][j] = INF;
            d = new int[size];
            for(int i=0 ; i<size ; i++)d[i] = INF;
            prev = new int[size];
            for(int i=0 ; i<size ; i++)prev[i] = 0;
            S = new bool[size];
            for(int i=0 ; i<size ; i++)S[i] = false;
        }
        void add_edge(int x, int y, int w) {
            arr[x][y] = w;
        }
        void dijkstra(int s, int e) {
            int ssize = 0;
            d[s] = 0;
            while(ssize != size) {
                int u = extractMin();
                S[u] = true;
                ssize++;
                for(int i=0 ; i<size ; i++) {
                    if(arr[u][i] != INF) {
                        if(S[i] == false && d[u] + arr[u][i] < d[i]) {
                            d[i] = d[u] + arr[u][i];
                            prev[i] = u+1;
                        }
                    }
                }
            }
            for(int i=0 ; i<size ; i++)printf("%d ", prev[i]);   
            if(d[e] == INF) printf("Impossible");
            else printf("%d", d[e]);
        }
        int extractMin() {
            int t;
            int min = INF;
            for(int i=0 ; i<size ; i++) {
                if(S[i] == false) {
                    if(min > d[i]) {
                        t = i;
                        min = d[i];
                    }
                }
            }
            return t;
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
    scanf("%d %d", &x, &y);
    graph.dijkstra(x-1, y-1);


    return 0;
}
