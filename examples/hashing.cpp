#include "../JDS/Hashing/hashing.hpp"

int main()
{
    int m = 5;
    int keys[10] {12, 7, 2, 43, 21, 8, 5, 3, 90, 10};
    SeparateChaining mySeparateChaining;
    SeparateChaining::Node** result = mySeparateChaining.separateChaining(keys, 10, m);

    for (int i=0; i<m-1; i++)
        for (SeparateChaining::Node* itter = result[i]; itter != nullptr; itter = itter->next)
            std::cout<<itter->data<<(itter->next != nullptr ? " -> " : "\n");

    mySeparateChaining.search(8, m, result);

    delete[] result;
    return 0;
}