#include "queue.hpp"
#include <iostream>

int main()
{
    Queue<int> myQueue(5);
    myQueue.add(1);
    myQueue.add(2);
    myQueue.add(3);
    myQueue.add(4);
    myQueue.add(5);
    for (int i=0; i<myQueue.size(); i++)
        std::cout<<myQueue.at(i)<<'\t';
    return 0;
}