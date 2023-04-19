#include "DWLL.hpp"
#include <iostream>
using std::cout;

int main()
{
    LL_DW myList({1, 2, 3, 4});
    myList.pop(0);
    myList.append(5);
    myList.insert(7, 2);
    
    for (int i=0; i<myList.size(); i++)
        cout<<myList.at(i)<<"\n";
}