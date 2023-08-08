#include <algorithm>

void merge(int* arr, const int start, const int middle, const int end) {
    int leftSize = middle - start + 1, rightSize = end - middle;
    int left[leftSize], right[rightSize];

    int i, j;
    for (i=0; i<leftSize; i++) left[i] = arr[i + start];
    for (j=0; j<rightSize; j++) right[j] = arr[j + middle + 1];

    i = j = 0;
    int resultIndex = start;
    while (i < leftSize && j < rightSize)
        if (left[i] < right[j])
            arr[resultIndex++] = left[i++];
        else
            arr[resultIndex++] = right[j++];

    while (i < leftSize) arr[resultIndex++] = left[i++];
    while (j < rightSize) arr[resultIndex++] = right[j++];
}

void mergeSort(int* arr, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}