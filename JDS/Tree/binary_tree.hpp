#include <iostream>

class BTree
{
public:
    typedef long long int lli;
    lli data;
    BTree* left = NULL;
    BTree* right = NULL;

    BTree* create(const lli& data)
    {
        BTree* t = new BTree;
        t->data = data;
        t->left = NULL;
        t->right = NULL;
        return t;
    }

    lli height(BTree* t) const
    {
        if (t == NULL)
            return -1;
        if (t->left == NULL && t->right == NULL)
            return 0;

        lli lh = height(t->left);
        lli rh = height(t->right);

        if (lh > rh)
            return lh + 1;
        else
            return rh + 1;
    }

    lli numof_nodes(BTree* t) const
    {
        if (t == NULL)
            return 0;
        return 1 + numof_nodes(t->left) + numof_nodes(t->right);
    }

    lli max(BTree* t) const
    {
        if (t == NULL)
            return INT32_MIN;

        lli m, lmax, rmax;
        m = t->data;
        lmax = max(t->left);
        rmax = max(t->right);

        if (lmax > m)
            m = lmax;
        if (rmax > m)
            m = rmax;

        return m;
    }

    void preorder(BTree* t)
    {
        if (t == NULL)
            return;
        std::cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }

    void deleteTree(BTree* t)
    {
        if (t == NULL)
            return;
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
};