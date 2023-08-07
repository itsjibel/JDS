#include "../JDS/Tree/binary_search_tree.hpp"

int main()
{
    BSTree *myBSTree = BSTree::createInstance(4);
    myBSTree->add(myBSTree->n, 3);
    myBSTree->add(myBSTree->n, 9);
    myBSTree->add(myBSTree->n, 12);
    myBSTree->add(myBSTree->n, 11);
    myBSTree->add(myBSTree->n, 7);
    myBSTree->add(myBSTree->n, 2);
    myBSTree->add(myBSTree->n, 6);

    std::cout<<"Height of Tree: "<<myBSTree->height(myBSTree->n)<<std::endl;

    std::cout<<"Inorder: ";
    myBSTree->inorder(myBSTree->n);
    std::cout<<std::endl;

    std::cout<<"Search result for 7: "<<(myBSTree->search(myBSTree->n, 7) ? "True" : "False")<<std::endl;

    myBSTree->deleteNode(myBSTree->n, 12);

    std::cout<<"Tree:"<<std::endl;
    myBSTree->draw_tree(myBSTree->n);

    myBSTree->deleteTree(myBSTree->n);
    return 0;
}