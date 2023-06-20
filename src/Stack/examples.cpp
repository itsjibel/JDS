#include <iostream>
#include "stack.hpp"

int main()
{
    Stack<std::string> myStack(5);
    myStack.push("Saul Goodman");
    myStack.push("Jesse Pinkman");
    myStack.push("Walter White");
    myStack.push("Hank Schrader");
    myStack.push("Gus Fring");
    myStack.pull();
    myStack.pull();
    myStack.pull();
    for (int i=0; i<myStack.size(); i++)
        std::cout<<myStack.at(i)<<std::endl;
    return 0;
}