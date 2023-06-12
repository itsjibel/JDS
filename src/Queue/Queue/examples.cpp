#include "queue.hpp"
#include <iostream>

int main()
{
    Queue<int> myQueue(5);
    for (int i=0; i<myQueue.size(); i++)
        myQueue.add(i);
    myQueue.del();
    for (int i=0; i<myQueue.size(); i++)
        std::cout<<myQueue.at(i)<<'\t';
    return 0;
}