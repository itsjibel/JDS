#include "../JDS/Queue/Circular-Queue/circular-queue.hpp" 
#include <iostream>

int main()
{
    CQueue<int> myCQueue(5);
    for (int i=0; i<7; i++)
        myCQueue.add(i);

    myCQueue.del();
    myCQueue.del();

    myCQueue.add(5);
    myCQueue.add(6);

    std::cout<<"Circular queue: ";
    for (int i=0; i<myCQueue.capacity(); i++)
        std::cout<<myCQueue.at(i)<<'\t';

    std::cout<<std::endl<<"Front: "<<myCQueue.get_front()<<std::endl;
    std::cout<<"Rear: "<<myCQueue.get_rear()<<std::endl;
    return 0;
}