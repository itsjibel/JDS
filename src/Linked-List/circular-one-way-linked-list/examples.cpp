#include "COWLL.hpp"
#include <iostream>

int main()
{
    COWLL<int> myList({2, 3, 4, 5, 6, 7});
    myList.pop(1);
    myList.insert(8, 4);
    myList.pop_back();
    myList.erase(4);
    std::cout<<"List 1: ["<<myList.at(0);
    for (int i=1; i<myList.size(); i++)
        std::cout<<" -> "<<myList.at(i);
    std::cout<<"]\n         ^------------------------=\n############## Break the list ##############\n";
    COWLL<int> myList2;
    myList2.start = myList.break_list();
    myList2.list_size = myList.list_size / 2;
    myList.list_size = myList.list_size - myList.list_size / 2;

    std::cout<<"List 1: ["<<myList.at(0);
    for (int i=1; i<myList.size(); i++)
        std::cout<<" -> "<<myList.at(i);
    std::cout<<"]\n";
    std::cout<<"List 2: ["<<myList2.at(0);
    for (int i=1; i<myList2.size(); i++)
        std::cout<<" -> "<<myList2.at(i);
    std::cout<<"]\n";
    return 0;
}