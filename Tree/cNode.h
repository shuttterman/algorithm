#ifndef CNODE_H
#define CNODE_H
template <typename T>
class cBinarySearchTree;

template <typename T>
class cNode {
friend class cBinarySearchTree<T>;
    private:
        cNode<T>* left;
        cNode<T>* right;
        T key;
    public:
        cNode(){}
        cNode(T t) {key = t; left = right = 0;}
};
#endif
