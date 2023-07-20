#include "../Binary-Tree/binary_tree.hpp"

class BSTree: public BTree
{
protected:
    BSTree(lli b)
    {
        Node* t = new Node;
        t->data = b;
        n = t;
    }

    BSTree() {}

public:
    Node* n;

    static BSTree* createInstance(lli b)
    {
        return new BSTree(b);
    }

    virtual Node* add(Node* t, const lli data)
    {
        if (t == NULL)
            return NULL;

        Node* a = new Node;
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

    bool search(Node* t, lli key)
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

    Node* min(Node* r)
    {
        Node* t;
        while (t->left != NULL)
            t = t->left;

        return t;
    }

    Node* deleteNode(Node* r, lli key)
    {
        if (r == NULL)
            return r;
        
        Node* t;

        if (key < r->data)
            r->left = deleteNode(r->left, key);
        else if (key > r->data)
            r->right = deleteNode(r->right, key);
        else {
            if (r->left == NULL)
            {
                t = r->right;
                delete r;
                return t;
            } else if (r->right == NULL) {
                t = r->left;
                delete r;
                return t;
            }

            t = min(r->right);
            r->data = t->data;
            r->right = deleteNode(r->right, t->data);
        }

        return r;
    }
};