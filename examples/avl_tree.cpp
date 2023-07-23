#include "../JDS/Tree/AVL-Tree/avl_tree.hpp"

int main()
{
    AVLTree* myAVLTree = AVLTree::createInstance(9);
    myAVLTree->add(myAVLTree->n, 56);
    myAVLTree->add(myAVLTree->n, 7);
    myAVLTree->add(myAVLTree->n, 23);
    myAVLTree->add(myAVLTree->n, 3);
    myAVLTree->add(myAVLTree->n, 5);
    myAVLTree->add(myAVLTree->n, 18);
    myAVLTree->add(myAVLTree->n, 8);

    std::cout<<"Tree:"<<std::endl;
    myAVLTree->draw_tree(myAVLTree->n);

    myAVLTree->deleteTree(myAVLTree->n);
    return 0;
}