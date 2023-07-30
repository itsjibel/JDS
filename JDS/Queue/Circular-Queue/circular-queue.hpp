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

        bool add(T val)
        {
            if (full())
                return false;
            if (_front == _capacity - 1 && _rear != 0)
            {
                _front = 0;
                queue[_front++] = val;
                _size++;
            } else if (_front < _capacity && (_front != _rear || size() == 0)) {
                queue[_front] = val;
                _front = _front < _capacity - 1 ? _front + 1 : _front;
                _size++;
            }
            return true;
        }

        T del()
        {
            if (empty())
                return false;
            _size--;
            return queue[_rear++];
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