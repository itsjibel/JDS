#include "../JDS/Tree/Heap-Tree/Max-Heap/max_heap.hpp"
#include <iostream>

int main()
{
    MaxHeap myMaxHeap;

    myMaxHeap.add(4);
    myMaxHeap.add(8);
    myMaxHeap.add(3);
    myMaxHeap.add(1);
    myMaxHeap.add(5);
    myMaxHeap.add(2);

    std::cout<<"Before: [";
    for (long long int i=0; i<myMaxHeap.size(); i++)
        std::cout<<myMaxHeap.max_heap_arr[i]<<(i < myMaxHeap.size() - 1 ? ", " : "");
    std::cout<<']'<<std::endl;

    myMaxHeap.remove();
    myMaxHeap.increase(1, 11);

    std::cout<<"Before: [";
    for (long long int i=0; i<myMaxHeap.size(); i++)
        std::cout<<myMaxHeap.max_heap_arr[i]<<(i < myMaxHeap.size() - 1 ? ", " : "");
    std::cout<<']'<<std::endl;

    long long int array[7] {92, 4, 13, 17, 2, 3, 21};

    std::cout<<"Array before heap sort: [";
    for (long long int i=0; i<7; i++)
        std::cout<<array[i]<<(i < 6 ? ", " : "");
    std::cout<<']'<<std::endl;

    myMaxHeap.heapSort(array, 7);

    std::cout<<"Array after heap sort:  [";
    for (long long int i=0; i<7; i++)
        std::cout<<array[i]<<(i < 6 ? ", " : "");
    std::cout<<']'<<std::endl;

    std::cout<<"Tree:"<<std::endl;
    myMaxHeap.draw_tree();

    return 0;
}