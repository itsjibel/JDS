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
        if (t == NULL)
            return NULL;

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

    void preorder(BSTree* t)
    {
        if (t == NULL)
            return;
        std::cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }

    void inorder(BSTree* t)
    {
        if (t == NULL)
            return;
        inorder(t->left);
        std::cout<<t->data<<" ";
        inorder(t->right);
    }

    void postorder(BSTree* t)
    {
        if (t == NULL)
            return;
        postorder(t->left);
        postorder(t->right);
        std::cout<<t->data<<" ";
    }

    bool search(BSTree* t, lli key)
    {
        if (t == NULL)
            return false;

        if (key == t->data)
            return true;

        if (key > t->data)
            search(t->right, key);
        else
            search(t->left, key);
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