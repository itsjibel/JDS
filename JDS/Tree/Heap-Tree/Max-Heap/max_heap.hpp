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
    }

    void MaxHeapify(lli i)
    {
    }

    lli remove()
    {
    }

    void increase(lli i, lli value)
    {
    }

    unsigned long int size() const
    {
        return max_heap_arr.size();
    }
};