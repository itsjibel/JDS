#include <iostream>

class SeparateChaining {
public:
    struct Node {
        int data {0};
        Node* next = nullptr;
        Node(int data) : data(data) {}
    };

    int h(int key, int m)
    {
        return key % m;
    }

    Node** separateChaining(const int keys[], int n, int m)
    {
        Node** result = new Node*[m];

        for (int i{0}; i<n; i++)
        {
            int hashResult = h(keys[i], m);
            if (result[hashResult] != nullptr)
            {
                Node* temp = result[hashResult]->next;
                result[hashResult]->next = new Node(keys[i]);
                result[hashResult]->next->next = temp;
            } else
                result[hashResult] = new Node(keys[i]);
        }
        return result;
    }

    void search(int key, int m, Node** result)
    {
        int hashResult = h(key, m);
        int index = 0;
        Node* itter = result[hashResult];
        while (itter->data != key)
            itter = itter->next, index++;

        if (itter->data == key)
            std::cout<<"'"<<key<<"' Found at chain "<<hashResult+1<<" and index "<<index<<std::endl;
        else
            std::cout<<"Not found in any chain"<<std::endl;
    }
};