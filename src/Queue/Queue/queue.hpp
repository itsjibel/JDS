template <typename T> class Queue
{
    private:
        T *queue;
        long long int front;
        long long int rear;
        long long int _size;

    public:
        unsigned long long int capacity;
        Queue(unsigned long long int c) : capacity{c}
        {
            queue = new T[capacity];
            front=0;
            rear=0;
            _size=0;
        }

        ~Queue()
        {
            delete[] queue;
        }

        bool is_empty() const
        {
            return _size == 0;
        }

        bool is_full() const
        {
            return _size == capacity;
        }

        bool add(T val)
        {
            if (is_full() || front == capacity)
                return false;
            queue[front++] = val;
            _size++;
            return true;
        }

        T at(unsigned long long int i) const
        {
            return queue[i];
        }

        unsigned long long int size() const
        {
            return capacity;
        }
};