#include "../JDS/Hashing/hashing.hpp"

int main()
{
    int m {5};
    int keys[10] {12, 7, 2, 43, 21, 8, 5, 3, 90, 10};
    SeparateChainingHashing mySeparateChaining;
    SeparateChainingHashing::Node** result = mySeparateChaining.hash(keys, 10, m);

    for (int i=0; i<m-1; i++)
        for (SeparateChainingHashing::Node* itter = result[i]; itter != nullptr; itter = itter->next)
            std::cout<<itter->data<<(itter->next != nullptr ? " -> " : "\n");

    mySeparateChaining.search(8, m, result);
    delete[] result;

    std::cout<<"----------------------------------------------------"<<std::endl;
    MultiplicationHashing myMultiplicationHashing;
    result = myMultiplicationHashing.hash(keys, 10, m);

    for (int i=0; i<m; i++)
        for (MultiplicationHashing::Node* itter = result[i]; itter != nullptr; itter = itter->next)
            std::cout<<itter->data<<(itter->next != nullptr ? " -> " : "\n");

    myMultiplicationHashing.search(43, m, result);
    delete[] result;

    return 0;
}