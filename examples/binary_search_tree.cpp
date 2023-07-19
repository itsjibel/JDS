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

    std::cout<<"Inorder: ";
    myBSTree->inorder(myBSTree);
    std::cout<<std::endl;

    std::cout<<"Search result for 7: "<<(myBSTree->search(myBSTree, 7) ? "True" : "False")<<std::endl;

    myBSTree->deleteNode(myBSTree, 12);

    std::cout<<"Tree:"<<std::endl;
    myBSTree->draw_tree(myBSTree);

    myBSTree->deleteTree(myBSTree);
    return 0;
}