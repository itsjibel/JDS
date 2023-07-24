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

    std::cout<<"Before: [";
    for (long long int i=0; i<myMaxHeap.size(); i++)
        std::cout<<myMaxHeap.max_heap_arr[i]<<(i < myMaxHeap.size() - 1 ? ", " : "");
    std::cout<<']'<<std::endl;

    return 0;
}