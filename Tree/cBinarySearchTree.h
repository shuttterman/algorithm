#ifndef CBINARYSEARCHTREE_H
#define CBINARYSEARCHTREE_H
#include "cNode.h"
#include <iostream>
using namespace std;

template <typename T>
class cBinarySearchTree{
    friend class cNode<T>;
    private:
        cNode<T>* treeInsert(cNode<T>* t, T x) {
            if(t==NULL) {
                cNode<T>* r = new cNode<T>(x);
                return r;
            }
            if(x<t->key) {
                t->left = treeInsert(t->left, x);
                return t;
            }
            else {
                t->right = treeInsert(t->right, x);
                return t;
            }
        }
        void treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p) {
            if(r==t)root=deleteNode(t);
            else if(r==p->left)p->left=deleteNode(r);
            else p->right=deleteNode(r);
        }
        cNode<T>* deleteNode(cNode<T>* r) {
            if((r->left==NULL) && (r->right==NULL))return NULL;
            else if((r->left==NULL) && (r->right!=NULL))return r->right;
            else if((r->left!=NULL) && (r->right==NULL))return r->left;
            else {
                cNode<T>* s = r->right;
                cNode<T>* parent;
                while(s->left!=NULL) {
                    parent=s;
                    s=s->left;
                }
                r->key = s->key;
                if(s==r->right)r->right=s->right;
                else parent->left=s->right;
                return r;
            }
        }
        void treePrint(cNode<T>* t, int step) {
            if(t!=NULL) {
                for(int i=0 ; i<step ; i++)printf("\t");
                cout << t->key << endl;
                step++;
                treePrint(t->left, step);
                treePrint(t->right,step);
            }
        }
        cNode<T>* root;
    public:
        cBinarySearchTree() {root=NULL;}
        ~cBinarySearchTree() {}
        void treeInsert(T x) {root=treeInsert(root, x);} 
        void treeDelete(T x) {
            cNode<T>* r;
            cNode<T>* p;
            r=root;
            p=NULL;
            while(r!=NULL) {
                if(r->key == x)break;
                else if(r->key<x) {
                    p=r;
                    r=r->right;
                }
                else {
                    p=r;
                    r=r->left;
                }
            }
            treeDelete(root, r, p);
        }
        void treePrint() { 
            treePrint(root, 0);
        }
};
#endif
