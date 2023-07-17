#include "../JDS/Tree/Binary-Tree/binary_tree.hpp"

int main()
{
    BTree *myBTree;
    myBTree = myBTree->create(9);
    myBTree->left = myBTree->create(3);
    myBTree->right = myBTree->create(1);
    myBTree->left->left = myBTree->create(8);
    myBTree->right->left = myBTree->create(2);
    myBTree->right->right = myBTree->create(6);
    myBTree->right->right->right = myBTree->create(4);
    myBTree->right->right->left = myBTree->create(0);
    myBTree->right->left->right = myBTree->create(5);
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

    std::cout<<"11 is on level "<<myBTree->find_level(myBTree, 11, 1)<<" of the tree"<<std::endl;

    std::cout<<"LCA of 2 and 6 is "<<myBTree->LCA(myBTree, 2, 6)->data<<std::endl;

    std::cout<<"tree:\n";
    myBTree->draw_tree(myBTree);

    myBTree->deleteTree(myBTree);
    return 0;
}