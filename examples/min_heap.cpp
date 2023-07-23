#include "../JDS/Tree/Heap-Tree/Min-Heap/min_heap.hpp"
#include <iostream>

int main()
{
    MinHeap myMinHeap;

    myMinHeap.add(4);
    myMinHeap.add(8);
    myMinHeap.add(3);
    myMinHeap.add(1);
    myMinHeap.add(5);
    myMinHeap.add(2);

    for (long long int number : myMinHeap.min_heap_arr)
        std::cout<<number<<std::endl;

    return 0;
}