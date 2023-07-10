#include <iostream>
#include "../JDS/Tree/binary_tree.hpp"

int main()
{
    BTree<int> *myBTree;
    myBTree = myBTree->create(9);
    myBTree->left = myBTree->create(3);
    myBTree->right = myBTree->create(5);
    myBTree->left->left = myBTree->create(11);
    myBTree->right->left->create(2);
    return 0;
}