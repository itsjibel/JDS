#include "COWLL.hpp"
#include <iostream>
using std::cout;

int main()
{
    COWLL myList({5, 4, 6});
    for (int i=0; i<myList.size(); i++)
        cout<<myList.at(i)<<"\n";
    return 0;
}