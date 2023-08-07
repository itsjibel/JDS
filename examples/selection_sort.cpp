#include "../JDS/Sort/selection.hpp"
#include <iostream>

int main()
{
    long long int array[10] {12, 43, 28, 13, 44, 8, 19, 42, 98, 91};
    auto arraySize = sizeof(array) / sizeof(long long int);
    selectionSort(array, arraySize);

    for (auto i{0}; i<arraySize; i++)
        std::cout<<array[i]<<(i < arraySize - 1 ? ", " : "\n");
    return 0;
}