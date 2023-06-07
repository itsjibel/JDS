template <typename T> class Queue
{
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

        T **queue;
        long long int front;
        long long int rear;
        long long int size;
};