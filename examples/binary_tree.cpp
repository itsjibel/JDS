#include "../JDS/Tree/binary_tree.hpp"

int main()
{
    BTree *myBTree = BTree::createInstance(9);
    myBTree->n->left = myBTree->add(3);
    myBTree->n->right = myBTree->add(1);
    myBTree->n->left->right = myBTree->add(8);
    myBTree->n->right->left = myBTree->add(2);
    myBTree->n->right->right = myBTree->add(61);
    myBTree->n->right->right->right = myBTree->add(412);
    myBTree->n->right->right->left = myBTree->add(0);
    myBTree->n->right->left->right = myBTree->add(5);
    myBTree->n->right->right->left->right = myBTree->add(21);
    std::cout<<"Hight of tree: "<<myBTree->height(myBTree->n)<<std::endl;
    std::cout<<"The number of tree nodes: "<<myBTree->numof_nodes(myBTree->n)<<std::endl;
    std::cout<<"The maximum value of the tree: "<<myBTree->max(myBTree->n)<<std::endl;
    std::cout<<"Preorder: ";
    myBTree->preorder(myBTree->n);
    std::cout<<std::endl;

    std::cout<<"Inorder: ";
    myBTree->inorder(myBTree->n);
    std::cout<<std::endl;

    std::cout<<"Postorder: ";
    myBTree->postorder(myBTree->n);
    std::cout<<std::endl;

    std::cout<<"Levelorder: ";
    myBTree->levelorder(myBTree->n);
    std::cout<<std::endl;

    std::cout<<"Identical: "<<(myBTree->identical(myBTree->n, myBTree->n) ? "True" : "False")<<std::endl;

    std::cout<<"Is the tree complete: "<<(myBTree->is_complete(myBTree->n) ? "True" : "False")<<std::endl;

    std::cout<<"61 is on level "<<myBTree->find_level(myBTree->n, 61, 1)<<" of the tree"<<std::endl;

    std::cout<<"LCA of 5 and 61 is "<<myBTree->LCA(myBTree->n, 5, 61)->data<<std::endl;

    std::cout<<"tree:\n";
    myBTree->draw_tree(myBTree->n);

    myBTree->deleteTree(myBTree->n);
    return 0;
}