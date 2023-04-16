#include "linked_list_one_way.hpp"
#include <iostream>
using std::cout;

int main()
{
    LL_OW myList;
    myList.create_node(3);
    myList.pop(6);
    myList.append(9);
    myList.insert(7, 2);
    myList.pop_back();
    myList.erase(0);
    cout<<myList.at(0)<<"\n";
    cout<<myList.at(1)<<"\n";
    cout<<myList.size()<<"\n";
    myList.free_list();
}