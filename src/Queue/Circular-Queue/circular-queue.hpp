template <typename T> class CQueue
{
    private:
        T *queue;
        long long int front;
        long long int rear;
        long long int _size;
        unsigned long long int capacity;

    public:
        CQueue(unsigned long long int c) : capacity{c}
        {
            queue = new T[capacity];
            front=0;
            rear=0;
            _size=0;
        }

        ~CQueue()
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
            if (is_full())
                return false;
            if (front < capacity)
            {
                queue[front++] = val;
                _size++;
            } else {
                front = 0;
                queue[front++] = val;
                _size++;
            }
            return true;
        }

        bool del()
        {
            if (is_empty())
                return false;
            queue[rear++] = 0;
            _size--;
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

        void clear()
        {
            _size = rear = front = 0;
            for (int i=0; i<capacity; i++)
                queue[i] = 0;
        }
};