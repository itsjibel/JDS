template <typename T> class Queue
{
    private:
        T **queue;
        long long int front=-1;
        long long int rear=-1;
        long long int size=0;

    public:
        unsigned long long int capacity;
        Queue(unsigned long long int c) : capacity{c}
        {
            queue = new T *[capacity];
        }
        
        ~Queue()
        {
            delete[] queue;
        }

        bool is_empty() const
        {
            return size == 0;
        }

        bool is_full() const
        {
            return size == capacity - 1;
        }
};