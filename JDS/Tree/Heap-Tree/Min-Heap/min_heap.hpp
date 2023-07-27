#include "../../Binary-Tree/binary_tree.hpp"

class MinHeap
{
private:
    typedef long long int lli;

public:
    std::vector<lli> min_heap_arr;

    lli parent (lli i)
    {
        return (i-1) / 2;
    }

    void add(lli val)
    {
        lli i = min_heap_arr.size();
        min_heap_arr.push_back(val);

        while (i != 0 && min_heap_arr[i] < min_heap_arr[parent(i)])
        {
            std::swap(min_heap_arr[i], min_heap_arr[parent(i)]);
            i = parent(i);
        }
    }

    void MinHeapify(lli i)
    {
        lli l = 2*i + 1;
        lli r = 2*i + 2;
        lli smallest = i;

        if (l < size() && min_heap_arr[l] < min_heap_arr[i])
            smallest = l;

        if (r < size() && min_heap_arr[r] < min_heap_arr[smallest])
            smallest = r;
    
        if (smallest != i)
        {
            std::swap(min_heap_arr[i], min_heap_arr[smallest]);
            MinHeapify(smallest);
        }
    }

    lli remove()
    {
        lli root = min_heap_arr[0];
        if (size() == 1)
        {
            min_heap_arr.pop_back();
            return root;
        }

        min_heap_arr[0] = min_heap_arr[size() - 1];
        min_heap_arr.pop_back();

        MinHeapify(0);

        return root;
    }

    void decrease(lli i, lli value)
    {
        min_heap_arr[i] = value;
        while (i != 0 && min_heap_arr[i] < min_heap_arr[parent(i)])
        {
            std::swap(min_heap_arr[i], min_heap_arr[parent(i)]);
            i = parent(i);
        }
    }

    void draw_tree()
    {
        lli how_many_nodes_in_level = 2, current_index = 1;
        BTree *root = min_heap_arr.size() != 0 ? BTree::createInstance(min_heap_arr[0]) : NULL;

        std::vector<BTree*> previous_level;
        std::vector<BTree*> level;
        previous_level.push_back(root);
        while (how_many_nodes_in_level < min_heap_arr.size())
        {
            for (lli i=current_index; i<how_many_nodes_in_level + current_index && i<min_heap_arr.size(); i++)
            {
                BTree *t = BTree::createInstance(min_heap_arr[i]);
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
        return min_heap_arr.size();
    }
};