#include <algorithm>

void selectionSort(long long int* arr, unsigned long int arrSize)
{
    for (auto i{0}; i<arrSize - 1; i++)
    {
        long long int minValIndex = i;
        for (auto j{i}; j<arrSize; j++)
            if (arr[j] < arr[minValIndex])
                minValIndex = j;

        auto j = i;
        while (arr[minValIndex] < arr[j])
            std::swap(arr[minValIndex], arr[j--]);
    }
}