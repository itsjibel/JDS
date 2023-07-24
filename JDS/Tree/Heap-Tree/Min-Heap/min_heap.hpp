#include <vector>

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

    unsigned long int size() const
    {
        return min_heap_arr.size();
    }
};