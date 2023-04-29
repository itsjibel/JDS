#include "COWLL.hpp"
#include <iostream>
using std::cout;

int main()
{
    COWLL myList({2, 3, 4, 5, 6, 7});
    myList.pop(1);
    myList.insert(8, 4);
    myList.pop_back();
    myList.erase(4);
    cout<<"List 1: ["<<myList.at(0);
    for (int i=1; i<myList.size(); i++)
        cout<<" -> "<<myList.at(i);
    cout<<"]\n";
    cout<<"         ^------------------------=\n";
    cout<<"############## Break the list ##############\n";
    COWLL myList2;
    myList2.start = myList.break_list();
    myList2.list_size = myList.list_size / 2;
    myList.list_size = myList.list_size - myList.list_size / 2;

    cout<<"List 1: ["<<myList.at(0);
    for (int i=1; i<myList.size(); i++)
        cout<<" -> "<<myList.at(i);
    cout<<"]\n";
    cout<<"List 2: ["<<myList2.at(0);
    for (int i=1; i<myList2.size(); i++)
        cout<<" -> "<<myList2.at(i);
    cout<<"]\n";
    return 0;
}