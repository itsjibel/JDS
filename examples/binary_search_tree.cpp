#include "../JDS/Tree/Binary-Search-Tree/binary_search_tree.hpp"

int main()
{
    BSTree *myBSTree = BSTree::createInstance(2);
    myBSTree = myBSTree->add(myBSTree, 9);
    myBSTree->add(myBSTree, 3);
    myBSTree->add(myBSTree, 12);
    myBSTree->add(myBSTree, 11);
    myBSTree->add(myBSTree, 7);
    myBSTree->add(myBSTree, 2);
    myBSTree->add(myBSTree, 6);
    myBSTree->deleteTree(myBSTree);
    return 0;
}