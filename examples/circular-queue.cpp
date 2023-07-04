#include "../JDS/Queue/Circular-Queue/circular-queue.hpp" 
#include <iostream>

int main()
{
    CQueue<int> myQueue(5);
    for (int i=1; i<=myQueue.size(); i++)
        myQueue.add(i);
    myQueue.del();
    myQueue.add(6);
    for (int i=0; i<myQueue.size(); i++)
        std::cout<<myQueue.at(i)<<'\t';
    return 0;
}