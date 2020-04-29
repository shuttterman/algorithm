#include <cstdio>

class node {
    private:
        node* r;
        node* n;
        node* tail;
    public:
        node(){
            r = this;
            n = NULL;
            tail = this;
        }
        node* find_set(node t) {
           return t.r; 
        }
        static void unio(node a, node b) {
            node* temp;
            a.tail->n = b.r;
            temp = b.r;
            while(temp != b.tail) {
                temp->r = a.r;
                temp = temp->n;
            }
            b.tail->r = a.r;
            temp = a.r;
            while(temp != b.tail) {
                temp->tail = b.tail;
                temp = temp->n;
            }
        }
        static int countf(node a) {
            int count=0;
            node* t;
            t=a.r;
            while(t != t->tail) {
                count++;
                t = t->n;
            }
            count++;
            return count;
        }
};
      

int main() {
    int size, m, a1, a2;
    int max;
    scanf("%d", &size);
    node* f= new node[size];
    scanf("%d", &m);
    for(int i=0 ; i<m ; i++) {
    scanf("%d %d", &a1, &a2);
    node::unio(f[a1-1], f[a2-1]);
    }
    max = node::countf(f[0]);
    for(int i=1 ; i<size ; i++) {
        max = (max < node::countf(f[i]) ? node::countf(f[i]) : max);
    }
    printf("%d\n", max);
    

    return 0;
}
