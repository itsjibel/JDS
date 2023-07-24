#include <vector>

class MaxHeap
{
private:
    typedef long long int lli;

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
        lli biggest = i;

        if (l < size() && max_heap_arr[l] > max_heap_arr[i])
            biggest = l;

        if (r < size() && max_heap_arr[r] > max_heap_arr[biggest])
            biggest = r;
    
        if (biggest != i)
        {
            std::swap(max_heap_arr[i], max_heap_arr[biggest]);
            MaxHeapify(biggest);
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
    }

    unsigned long int size() const
    {
        return max_heap_arr.size();
    }
};