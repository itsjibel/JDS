#include "../JDS/Hashing/hashing.hpp"
#include <iostream>

int main()
{
    int array[10] {12, 7, 2, 43, 21, 8, 2, 3, 90, 2};
    separateChaining(array, 5);
    return 0;
}