#include "../JDS/Tree/Binary-Tree/binary_tree.hpp"

int main()
{
    BTree *myBTree;
    myBTree = myBTree->create(9);
    myBTree->left = myBTree->create(3);
    myBTree->right = myBTree->create(1);
    myBTree->left->right = myBTree->create(8);
    myBTree->right->left = myBTree->create(2);
    myBTree->right->right = myBTree->create(61);
    myBTree->right->right->right = myBTree->create(412);
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

    std::cout<<"61 is on level "<<myBTree->find_level(myBTree, 61, 1)<<" of the tree"<<std::endl;

    std::cout<<"LCA of 5 and 61 is "<<myBTree->LCA(myBTree, 5, 61)->data<<std::endl;

    std::cout<<"tree:\n";
    myBTree->draw_tree(myBTree);

    myBTree->deleteTree(myBTree);
    return 0;
}