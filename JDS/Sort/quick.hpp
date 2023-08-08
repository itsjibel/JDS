#include <algorithm>

int partition(int* arr, const int start, const int end) {
    int i = start;
    for (int j=start; j<end; j++)
        if (arr[j] <= arr[end])
            std::swap(arr[j], arr[i++]);

    std::swap(arr[end], arr[i]);
    return i;
}

void quickSort(int* arr, const int start, const int end) {
    if (start < end) {
        int q = partition(arr, start, end);
        quickSort(arr, start, q - 1);
        quickSort(arr, q + 1, end);
    }
}