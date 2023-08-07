#include "../JDS/Sort/bubble.hpp"
#include <iostream>

int main()
{
    long long int array[10] {23, 43, 7, 5, -2, 13, 6, 10, 0, 21};
    auto arraySize = sizeof(array) / sizeof(long long int);
    bubbleSort(array, arraySize);

    for (auto i{0}; i<arraySize; i++)
        std::cout<<array[i]<<(i < arraySize - 1 ? ", " : "\n");
    return 0;
}