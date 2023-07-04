#include <iostream>
#include "../JDS/Stack/stack.hpp"

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
    for (int i=0; i<=myStack.top_val(); i++)
        std::cout<<myStack.at(i)<<std::endl;
    
    std::string str("(25+3)*4+65-(98-3)");
    std::string postfix_result = stack::infix2postfix(str);
    std::cout<<stack::calculate_postfix(postfix_result)<<std::endl;
    return 0;
}