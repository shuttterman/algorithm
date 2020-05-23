#include <cstdio>

class Graph {
    private :
        int** arr;
        int* visited;
        int size;
    public :
        Graph(int size) {
            this->arr = new int*[size];
            for(int i=0 ; i<size ; i++)this->arr[i]=new int[size];
            for(int i=0 ; i<size ; i++) 
                for(int j=0 ; j<size ; j++) 
                    this->arr[i][j] = 0;
            this->visited = new int[size];
            for(int i=0 ; i<size ; i++)this->visited[i] = 0;
            this->size = size;
        }
        void add_edge(int x, int y) {
            this->arr[x][y] = 1;
            this->arr[y][x] = 1;
        }
        void DFS(int start) {
            int temp;
            for(int i=0 ; i<this->size ; i++) {
                temp = (start+i)%size;
                if(visited[temp]==0)dfs(temp);
            }
        }
        void dfs(int s) {
            printf("%d ", s+1);
            visited[s] = 1;
            for(int i=0 ; i<size ; i++) {
                if(arr[s][i]==1) {
                    if(visited[i]==0)dfs(i);
                }
            }
        }
};
int main() {

    int size, count;
    int x, y;
    scanf("%d", &size);
    Graph graph(size);
    scanf("%d", &count);
    for(int i=0 ; i<count ; i++) {
        scanf("%d %d", &x, &y);
        graph.add_edge(x-1, y-1);
    }
    scanf("%d", &count);
    graph.DFS(count-1);

    return 0;
}
