#include "../JDS/Linked-List/double-way-linked-list/DWLL.hpp" 
#include <iostream>

int main()
{
    DWLL<int> myList({1, 2, 3, 4});
    myList.pop(0);
    myList.append(5);
    myList.insert(7, 2);
    myList.erase(5);
    myList.pop_back();
    DWLL<int> myList2({4, 5, 6});
    myList.concat(myList2);

    for (int i=0; i<myList.size(); i++)
        std::cout<<myList.at(i)<<", ";
    std::cout<<std::endl;
    myList.reverse();
    for (int i=0; i<myList.size(); i++)
        std::cout<<myList.at(i)<<", ";
    std::cout<<"\n";
    return 0;
}