#include "../JDS/Sort/insertion.hpp"
#include <iostream>

int main()
{
    long long int array[10] {32, 1, 5, 23, 8, 3, 12, 4, 56, 14};
    auto arraySize {sizeof(array) / sizeof(long long int)};
    insertionSort(array, arraySize);

    for (auto i{0}; i<arraySize; i++)
        std::cout<<array[i]<<(i < arraySize - 1 ? ", " : "\n");
    return 0;
}