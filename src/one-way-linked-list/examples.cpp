#include "OWLL.hpp"
#include <iostream>
using std::cout;

int main()
{
    LL_OW myList({5, 4, 6});
    myList.pop(6);
    myList.append(9);
    myList.insert(7, 2);
    myList.pop_back();
    myList.erase(0);
    for (int i=0; i<myList.size(); i++)
        cout<<myList.at(i)<<"\n";
    return 0;
}