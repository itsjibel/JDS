#include <algorithm>

void insertionSort(long long int* arr, unsigned long int arrSize)
{
    if (arrSize == 1)
        return;

    for (auto i{1}; i<arrSize; i++)
    {
        auto j {i};
        while (arr[j] < arr[j-1] && j > 0)
        {
            std::swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}