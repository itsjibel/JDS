#include "COWLL.hpp"
#include <iostream>
using std::cout;

int main()
{
    COWLL myList({4, 5, 6, 7});
    myList.pop(3);
    myList.insert(8, 4);
    myList.pop_back();
    myList.erase(4);
    cout<<"["<<myList.at(0);
    for (int i=1; i<myList.size(); i++)
        cout<<" -> "<<myList.at(i);
    cout<<"]\n";
    return 0;
}