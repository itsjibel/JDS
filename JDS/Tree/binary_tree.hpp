#include <iostream>
template<typename T> class BTree
{
public:
    T data;
    BTree* left = NULL;
    BTree* right = NULL;

    BTree* create(const T& data)
    {
        BTree* t = new BTree;
        t->data = data;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
};