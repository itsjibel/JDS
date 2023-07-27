#include "../../Binary-Tree/binary_tree.hpp"

class MaxHeap
{
private:
    typedef long long int lli;

    void Max_Heapify(lli arr[], lli n, lli i)
    {
        lli l = 2*i + 1;
        lli r = 2*i + 2;
        lli largest = i;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;
    
        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);
            Max_Heapify(arr, n, largest);
        }
    }

public:
    std::vector<lli> max_heap_arr;

    lli parent (lli i)
    {
        return (i-1) / 2;
    }

    void add(lli val)
    {
        lli i = max_heap_arr.size();
        max_heap_arr.push_back(val);

        while (i != 0 && max_heap_arr[i] > max_heap_arr[parent(i)])
        {
            std::swap(max_heap_arr[i], max_heap_arr[parent(i)]);
            i = parent(i);
        }
    }

    void MaxHeapify(lli i)
    {
        lli l = 2*i + 1;
        lli r = 2*i + 2;
        lli largest = i;

        if (l < size() && max_heap_arr[l] > max_heap_arr[i])
            largest = l;

        if (r < size() && max_heap_arr[r] > max_heap_arr[largest])
            largest = r;
    
        if (largest != i)
        {
            std::swap(max_heap_arr[i], max_heap_arr[largest]);
            MaxHeapify(largest);
        }
    }

    lli remove()
    {
        lli root = max_heap_arr[0];
        if (size() == 1)
        {
            max_heap_arr.pop_back();
            return root;
        }

        max_heap_arr[0] = max_heap_arr[size() - 1];
        max_heap_arr.pop_back();

        MaxHeapify(0);

        return root;
    }

    void increase(lli i, lli value)
    {
        max_heap_arr[i] = value;
        while (i != 0 && max_heap_arr[i] > max_heap_arr[parent(i)])
        {
            std::swap(max_heap_arr[i], max_heap_arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapSort(lli arr[], lli n)
    {
        for (lli i=n/2-1; i>=0; i--)
            Max_Heapify(arr, n, i);

        for (lli i=n-1; i>=0; i--)
        {
            std::swap(arr[0], arr[i]);
            Max_Heapify(arr, i, 0);
        }
    }

    void draw_tree()
    {
        lli how_many_nodes_in_level = 2, current_index = 1;
        BTree *root = max_heap_arr.size() != 0 ? BTree::createInstance(max_heap_arr[0]) : NULL;

        std::vector<BTree*> previous_level;
        std::vector<BTree*> level;
        previous_level.push_back(root);
        while (how_many_nodes_in_level < max_heap_arr.size())
        {
            for (lli i=current_index; i<how_many_nodes_in_level + current_index && i<max_heap_arr.size(); i++)
            {
                BTree *t = BTree::createInstance(max_heap_arr[i]);
                level.push_back(t);
            }

            lli i = 0;
            for (auto node : previous_level)
                if (i + 1 < level.size())
                {
                    node->n->left = level.at(i++)->n;
                    node->n->right = level.at(i++)->n;
                }

            previous_level = level;
            level.clear();
            current_index += how_many_nodes_in_level;
            how_many_nodes_in_level *= 2;
        }

        root->draw_tree(root->n);
    }

    unsigned long int size() const
    {
        return max_heap_arr.size();
    }
};