#include <iostream>
#include "../JDS/Tree/binary_tree.hpp"

int main()
{
    BTree *myBTree;
    myBTree = myBTree->create(9);
    myBTree->left = myBTree->create(3);
    myBTree->right = myBTree->create(12);
    myBTree->left->left = myBTree->create(11);
    myBTree->left->right = myBTree->create(7);
    myBTree->right->left = myBTree->create(2);
    myBTree->right->right = myBTree->create(6);
    std::cout<<"Hight of tree: "<<myBTree->height(myBTree)<<std::endl;
    std::cout<<"The number of tree nodes: "<<myBTree->numof_nodes(myBTree)<<std::endl;
    std::cout<<"The maximum value of the tree: "<<myBTree->max(myBTree)<<std::endl;
    std::cout<<"Preorder: ";
    myBTree->preorder(myBTree);
    std::cout<<std::endl;

    std::cout<<"Inorder: ";
    myBTree->inorder(myBTree);
    std::cout<<std::endl;

    std::cout<<"Postorder: ";
    myBTree->postorder(myBTree);
    std::cout<<std::endl;

    std::cout<<"Levelorder: ";
    myBTree->levelorder(myBTree);
    std::cout<<std::endl;

    std::cout<<"Identical: "<<(myBTree->identical(myBTree, myBTree) ? "True" : "False")<<std::endl;

    std::cout<<"Is the tree complete: "<<(myBTree->is_complete(myBTree) ? "True" : "False")<<std::endl;

    myBTree->deleteTree(myBTree);
    return 0;
}