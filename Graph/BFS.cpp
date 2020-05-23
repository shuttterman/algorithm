#include <cstdio>
#include <queue>
using namespace std;

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
        void BFS(int start) {
            int temp;
            for(int i=0 ; i<this->size ; i++) {
                temp = (start+i)%size;
                if(visited[temp]==0)bfs(temp);
            }
        }
        void bfs(int s) {
            queue<int> q;
            printf("%d ", s+1);
            visited[s] = 1;
            q.push(s);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int i=0 ; i<size ; i++) {
                    if(arr[u][i]==1) {
                        if(visited[i] == 0) {
                            printf("%d ", i+1);
                            visited[i] = 1;
                            q.push(i);
                        }
                    }
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
    graph.bfs(count-1);

    return 0;
}
