#include <vector>

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

    unsigned long int size() const
    {
        return max_heap_arr.size();
    }
};