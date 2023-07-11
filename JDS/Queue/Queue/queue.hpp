template <typename T> class Queue
{
    private:
        T *queue;
        long long int front;
        long long int rear;
        long long int _size;
        unsigned long long int capacity;

    public:
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

        T del()
        {
            if (is_empty())
                return queue[0];
            _size--;
            return queue[rear++];
        }

        T at(unsigned long long int i) const
        {
            return queue[i];
        }

        unsigned long long int size() const
        {
            return _size;
        }

        void clear()
        {
            _size = rear = front = 0;
            for (int i=0; i<capacity; i++)
                queue[i] = 0;
        }
};