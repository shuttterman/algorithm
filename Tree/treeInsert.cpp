#include <cstdio>
int cnt;
class node {
    private:
        node* left;
        node* right;
        int data;
    public:
        node(int x){data = x; left=right=NULL;}
        int getdata(){return data;}
        void setleft(node* l){left=l;}
        void setright(node* r){right=r;}
        node* getleft(){return left;}
        node* getright(){return right;}
};
class bst {
    private:
        node* root;
    public:
        bst(){root=NULL;}
        void in_sert(int x){
            cnt++;
            if(root==NULL)root=insert(root, x); 
            else insert(root, x);
        }
        node* insert(node* n, int x){
            if(n==NULL) {
                node* r = new node(x);
                return r;
            }
            if(x<n->getdata()) {
               n->setleft(insert(n->getleft(), x));
               cnt++;
               return n;
            }
            else {
                n->setright(insert(n->getright(), x));
                cnt++;
                return n;
            }
        }
};
int main(){
    bst tree;
    int size;
    int temp;
    scanf("%d", &size);
    for(int i=0 ; i<size ; i++){
        scanf("%d", &temp);
        tree.in_sert(temp);
    }
    printf("%d", cnt);
    return 0;
}

