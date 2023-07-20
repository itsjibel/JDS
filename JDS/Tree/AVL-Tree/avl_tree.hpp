#include "../Binary-Search-Tree/binary_search_tree.hpp"

class AVLTree: public BSTree
{
protected:
    typedef long long int lli;
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
};