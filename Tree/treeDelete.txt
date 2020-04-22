#include <cstdio>
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
        void setdata(int x){data=x;}
        node* getleft(){return left;}
        node* getright(){return right;}
};
class bst {
    private:
        node* root;
    public:
        bst(){root=NULL;}
        node* temp;
        node* search(node* t, int x) {
           if((t==NULL)||(t->getdata()==x))return t;
           if(x<t->getdata()) {
               temp=t;
               return search(t->getleft(), x);
           }
           else {
               temp=t;
               return search(t->getright(), x);
           }
        }
        void in_sert(int x){
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
               return n;
            }
            else {
                n->setright(insert(n->getright(), x));
                return n;
            }
        }
        void del(int x){
            node* tmp = search(root, x);
            treeDelete(root, tmp, temp);
        }
        void treeDelete(node* t, node* r, node* p) {
            if(r==t)root=Delete(t);
            else if(r==p->getleft())p->setleft(Delete(r));
            else p->setright(Delete(r));
        }
        node* Delete(node* r) {
            if((r->getleft()==NULL) && (r->getright()==NULL)) return NULL;
            else if((r->getleft()==NULL) && (r->getright()!=NULL)) return r->getright();
            else if((r->getleft()!=NULL) && (r->getright()==NULL)) return r->getleft();
            else {
                node* s = new node(0);
                node* parent = new node(0);
                s=r->getright();
                while(s->getleft() != NULL) {
                    parent = s;
                    s = s->getleft();
                }
                r->setdata(s->getdata());
                if(s==r->getright())r->setright(s->getright());
                else parent->setleft(s->getright());
                return r;
            }
        }
        void preorder(){pre_order(root);}
        void pre_order(node* r) {
            if(r!=NULL) {
                printf("%d ", r->getdata());
                pre_order(r->getleft());
                pre_order(r->getright());
            }
        }
        void inorder(){in_order(root);}
        void in_order(node* r) {
            if(r!=NULL) {
                in_order(r->getleft());
                printf("%d ", r->getdata());
                in_order(r->getright());
            }
        }
        void postorder(){post_order(root);}
        void post_order(node* r) {
            if(r!=NULL) {
                post_order(r->getleft());
                post_order(r->getright());
                printf("%d ", r->getdata());
            }
        }
        
};
int main(){
    bst tree;
    int size;
    int tmp;
    int temp;
    scanf("%d", &size);
    for(int i=0 ; i<size ; i++){
        scanf("%d", &temp);
        tree.in_sert(temp);
    }
    scanf("%d", &size);
    for(int i=0 ; i<size ; i++) {
        scanf("%d %d", &temp, &tmp);
        tree.del(tmp);
        switch (temp) {
            case 0:
                tree.preorder();
                printf("\n");
                break;
            case 1:
                tree.inorder();
                printf("\n");
                break;
            case 2:
                tree.postorder();
                printf("\n");
                break;
        }
    }
    return 0;
}
