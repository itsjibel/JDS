#include "linked_list_one_way.hpp"

int main()
{
    LL_OW myList;
    myList.create_node(3);
    myList.pop(6);        
    myList.append(9);
    myList.insert(7, 2);
    myList.pop_back();  
        myList.erase(0);
    myList.show();      
    myList.free_list();
}