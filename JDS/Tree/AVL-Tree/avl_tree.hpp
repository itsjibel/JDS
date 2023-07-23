#include "../Binary-Search-Tree/binary_search_tree.hpp"

class AVLTree: public BSTree
{
protected:
    AVLTree(lli b)
    {
        Node* t = new Node;
        t->data = b;
        n = t;
    }

    AVLTree() {}

public:
    Node* n;

    static AVLTree* createInstance(lli b)
    {
        return new AVLTree(b);
    }

    Node* rightRotate(Node* y)
    {
        Node *x, *T2;

        x = y->left;
        T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node *y, *T2;

        y = x->right;
        T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    lli balance(Node* p)
    {
        if (p == NULL)
            return 0;
        return height(p->left) - height(p->right);
    }

    Node* add(Node* p, const lli data)
    {
        if (p == NULL)
        {
            Node* np = new Node;
            np->data = data;
            return np;
        }

        if (data < p->data)
            p->left = add(p->left, data);
        else if (data > p->data)
            p->right = add(p->right, data);
        else
            return p;

        p->height = 1 + std::max(height(p->left), height(p->right));

        lli b = balance(p);

        if (p->left != NULL)
        if (b >= 2 && data < p->left->data)
            return rightRotate(p);

        if (p->right != NULL)
        if (b >= -2 && data > p->right->data)
            return leftRotate(p);

        if (b >= 2 && data > p->left->data)
        {
            p->left = leftRotate(p->left);
            return rightRotate(p);
        }

        if (b <= -2 && data < p->right->data)
        {
            p->right = rightRotate(p->right);
            return leftRotate(p);
        }

        return p;
    }
};