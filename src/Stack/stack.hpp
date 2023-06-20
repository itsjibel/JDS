template <typename T> class Stack
{
    private:
        T *stack;
        long long int top;
        unsigned long long int capacity;

    public:
        Stack (unsigned long long int c) : capacity{c}
        {
            stack = new T[capacity];
            top = -1;
        }

        ~Stack()
        {
            delete[] stack;
        }

        bool is_empty() const
        {
            return top == -1;
        }

        bool is_full() const
        {
            return top == capacity;
        }

        bool push(T val)
        {
            if (is_full())
                return false;
            if (top == -1)
                top = 0;
            stack[top++] = val;
            return true;
        }

        bool pull()
        {
            if (is_empty())
                return false;
            if (top == capacity)
                top--;
            stack[top--] = "";
            return true;
        }

        T at(unsigned long long int i) const
        {
            return stack[i];
        }

        unsigned long long int size() const
        {
            return capacity;
        }

        void clear()
        {
            top = -1;
            for (int i=0; i<capacity; i++)
                stack[i] = 0;
        }
};