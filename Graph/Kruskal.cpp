#include <cstdio>

class Set {
    private : 
        Set* n; 
        Set* tail;
    public :
        Set(){n = this;tail = this;}
        Set* find_set() {
            Set* r=this;
            while(r->n!=r) {
                r = r->n;
            }
            return r;
        }
        static void Union(Set* a, Set* b) {
            Set* t=a->tail;
            b->find_set()->n = a->tail;
            while(t != t->find_set()) {
                t->tail = b->tail;
                t = t->n;
            }
        }
};

class Graph {
    private :
        int** arr;
        int size;
    public :
        Graph(int size) {
            this->arr = new int*[size];
            for(int i=0 ; i<size ; i++)this->arr[i]=new int[size];
            for(int i=0 ; i<size ; i++) 
                for(int j=0 ; j<size ; j++) 
                    this->arr[i][j] = 99999;
            this->size = size;
        }
        void add_edge(int x, int y, int w) {
            this->arr[x][y] = w;
            this->arr[y][x] = w;
        }
        void print() {
            for(int i=0 ; i<size ; i++) {
                for(int j=0 ; j<size ; j++) {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
        }

        
        void kruskal() {
            int x, y;
            int total = 0;
            int min;
            int s = size;
            Set* set = new Set[s]; 
            while(s-1 >0) {
                min = 99999;
                for(int i=0 ; i<size ; i++) {
                    for(int j=0 ; j<size ; j++) {
                        if(min > arr[i][j]) {
                            min = arr[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
                if(set[x].find_set() != set[y].find_set()) {
                    total+=arr[x][y];
                    printf("%d ", arr[x][y]);
                    Set::Union(set[x].find_set(), set[y].find_set());
                    arr[x][y] = 99999;
                    arr[y][x] = 99999;
                    s--;
                }
                else {
                    arr[x][y] = 99999;
                    arr[y][x] = 99999;
                }
            }
            printf("%d", total);
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
    graph.kruskal();
    return 0;
}
