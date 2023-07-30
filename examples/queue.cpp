#include "../JDS/Queue/Queue/queue.hpp"
#include <iostream>

int main()
{
    Queue<int> myQueue(5);
    for (int i=0; i<myQueue.capacity(); i++)
        myQueue.add(i);
    myQueue.del();

    std::cout<<"Queue: ";
    for (int i=myQueue.get_rear(); i<=myQueue.get_front(); i++)
        std::cout<<myQueue.at(i)<<'\t';

    std::cout<<std::endl<<"Front: "<<myQueue.front()<<std::endl;
    std::cout<<"Rear: "<<myQueue.rear()<<std::endl;

    return 0;
}