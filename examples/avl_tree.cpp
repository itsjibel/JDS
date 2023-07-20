#include "../JDS/Tree/AVL-Tree/avl_tree.hpp"

int main()
{
    AVLTree* myAVLTree = AVLTree::createInstance(9);

    myAVLTree->deleteTree(myAVLTree->n);
    return 0;
}