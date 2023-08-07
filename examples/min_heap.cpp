#include "../JDS/Tree/min_heap.hpp"
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

    std::cout<<"Before: [";
    for (long long int i=0; i<myMinHeap.size(); i++)
        std::cout<<myMinHeap.min_heap_arr[i]<<(i < myMinHeap.size() - 1 ? ", " : "");
    std::cout<<']'<<std::endl;

    myMinHeap.remove();
    myMinHeap.decrease(3, 0);

    std::cout<<"After:  [";
    for (long long int i=0; i<myMinHeap.size(); i++)
        std::cout<<myMinHeap.min_heap_arr[i]<<(i < myMinHeap.size() - 1 ? ", " : "");
    std::cout<<']'<<std::endl;

    std::cout<<"Tree:"<<std::endl;
    myMinHeap.draw_tree();

    return 0;
}