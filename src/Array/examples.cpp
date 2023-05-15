#include <iostream>
#include "array.hpp"
using std::cout;

int main()
{
    int a[4] {1, 5, 8, 92};
    cout<<lsearch(a, sizeof(a)/4, 5)<<'\n';
    cout<<bsearch(a, 0, sizeof(a)/4, 92)<<'\n';
    cout<<ibsearch(a, 0, sizeof(a)/4, 8)<<'\n';
    bdel(a, sizeof(a)/4, 8);
    cout<<ibsearch(a, 0, sizeof(a)/4, 8)<<'\n';
    del(a, sizeof(a)/4, 5);
    cout<<bsearch(a, 0, sizeof(a)/4, 5)<<'\n';

    return 0;
}