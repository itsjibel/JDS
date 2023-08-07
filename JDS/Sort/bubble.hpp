#include <algorithm>

void bubbleSort(long long int* arr, unsigned long int arrSize)
{
    for (auto i{0}; i<arrSize - 1; i++)
        for (auto j{0}; j<arrSize - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}