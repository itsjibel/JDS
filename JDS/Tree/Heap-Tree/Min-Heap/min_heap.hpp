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

    unsigned long int size() const
    {
        return min_heap_arr.size();
    }
};