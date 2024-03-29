template <typename T> class CQueue
{
    private:
        T *queue;
        long long int _front;
        long long int _rear;
        long long int _size;
        unsigned long long int _capacity;

    public:
        CQueue(unsigned long long int c) : _capacity{c}
        {
            queue = new T[_capacity];
            _front=0;
            _rear=0;
            _size=0;
        }

        ~CQueue()
        {
            delete[] queue;
        }

        bool empty() const
        {
            return _size == 0;
        }

        bool full() const
        {
            return _size == _capacity;
        }

        bool push(T val)
        {
            if (full())
                return false;

            queue[_rear] = val;
            _rear = (_rear + 1) % _capacity;
            _size++;
            return true;
        }

        T pop()
        {
            if (empty())
                return -1;

            T val = queue[_front];
            _front = (_front + 1) % _capacity;
            _size--;
            return val;
        }

        T at(unsigned long long int i) const
        {
            return queue[i];
        }

        unsigned long long int size() const
        {
            return _size;
        }

        unsigned long long int capacity() const
        {
            return _capacity;
        }

        T front() const
        {
            return queue[_front];
        }

        T rear() const
        {
            return queue[_rear];
        }

        unsigned long long int get_front() const
        {
            return _front;
        }

        unsigned long long int get_rear() const
        {
            return _rear;
        }

        void clear()
        {
            _size = _rear = _front = 0;
            for (int i=0; i<_capacity; i++)
                queue[i] = 0;
        }
};