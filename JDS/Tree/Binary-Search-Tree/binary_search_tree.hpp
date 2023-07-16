#include <iostream>

class BSTree
{
private:
    typedef long long int lli;
    BSTree(lli b) {}
    BSTree() {}

public:
    lli data;
    BSTree* left = NULL;
    BSTree* right = NULL;

    static BSTree* createInstance(lli b)
    {
        return new BSTree(b);
    }

    BSTree* add(BSTree* t, const lli data)
    {
        BSTree* a = new BSTree;
        a->data = data;
        if (data > t->data)
        {
            if (t->right == NULL)
                t->right = a;
            else
                add(t->right, data);
        } else {
            if (t->left == NULL)
                t->left = a;
            else
                add(t->left, data);
        }
        return a;
    }

    void deleteTree(BSTree* t)
    {
        if (t == NULL)
            return;
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
};