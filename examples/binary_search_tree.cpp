#include <iostream>
#include "../JDS/Tree/Binary-Search-Tree/binary_search_tree.hpp"

int main()
{
    BSTree *myBSTree;
    myBSTree = myBSTree->create(9);
    myBSTree->left = myBSTree->create(3);
    myBSTree->right = myBSTree->create(12);
    myBSTree->left->left = myBSTree->create(11);
    myBSTree->left->right = myBSTree->create(7);
    myBSTree->right->left = myBSTree->create(2);
    myBSTree->right->right = myBSTree->create(6);

    myBSTree->deleteTree(myBSTree);
    return 0;
}