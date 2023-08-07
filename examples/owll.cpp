#include "../JDS/Linked-List/OWLL.hpp" 
#include <iostream>

int main()
{
    OWLL<std::string> myList({"Jack", "Skyler", "Hank", "Jibel"});
    myList.pop("Saul");
    myList.append("Walter");
    myList.insert("Jesse", 2);
    myList.pop_back();
    myList.erase(4);
    myList.erase(1);
    for (int i=0; i<myList.size(); i++)
        std::cout<<myList.at(i)<<"\n";
    return 0;
}