#include <iostream>
#include <vector>
#include <math.h>

class AVLTree
{
private:
    typedef long long int lli;
    AVLTree(lli b) {}
    AVLTree() {}

public:
    lli data;
    AVLTree* left = NULL;
    AVLTree* right = NULL;

    static AVLTree* createInstance(lli b)
    {
        return new AVLTree(b);
    }

    void deleteTree(AVLTree* t)
    {
        if (t == NULL)
            return;
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
};