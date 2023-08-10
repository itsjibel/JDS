#include <iostream>
#include <math.h>

class SeparateChainingHashing {
public:
    struct Node {
        int data {0};
        Node* next = nullptr;
        Node(int data) : data(data) {}
    };

    virtual int h(const int key, const int m)
    {
        return key % m;
    }

    Node** hash(const int keys[], int n, int m)
    {
        Node** result = new Node*[m];
        for (int i{0}; i<m; i++)
            result[i] = nullptr;

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

    void search(const int key, const int m, Node** result)
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

class MultiplicationHashing : public SeparateChainingHashing {
public:
    int h(const int key, const int m) override
    {
        double A = (sqrt(5) - 1) / 2;
        return static_cast<int>(floor(m * fmod(key * A, 1.0)));
    }
};

class LinearHashing {
public:
    virtual int h(int key, int m, int i)
    {
        return (key % m + i) % m;
    }

    int* hash(const int keys[], int n, int m)
    {
        int* result = new int[m];
        for (int i{0}; i<m; i++)
            result[i] = -1;

        for (int i=0; i<n; i++)
        {
            int j = 0;
            int hashResult = h(keys[i], m, j);
            while (result[hashResult] != -1)
                hashResult = h(keys[i], m, j++);
            result[hashResult] = keys[i];
        }
        return result;
    }

    void search(const int key, const int m, const int* result)
    {
        int i = 0;
        int hashResult = h(key, m, i);
        while (result[hashResult] != key && i < m)
            hashResult = h(key, m, i++);

        if (i == m && result[hashResult] != key)
            std::cout<<"Not found"<<std::endl;
        else
            std::cout<<"'"<<key<<"' Found at index "<<hashResult<<std::endl;
    }
};