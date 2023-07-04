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

        T push(T val)
        {
            return stack[++top] = val;
        }

        T pull()
        {
            if (!is_empty())
                return stack[top--];
            return 0;
        }

        T at(unsigned long long int i) const
        {
            return stack[i];
        }

        T at_top() const
        {
            return stack[top];
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

        long long int top_val()
        {
            return top;
        }

};

namespace stack
{
    int prec(char ch)
    {
        switch (ch)
        {
            case '+': case '-': return 1; break;
            case '*': case '/': return 2; break;
            case '^': return 3;
        }
        return -1;
    }

    std::string infix2postfix(std::string& s)
    {
        Stack<char> st(s.size()); //For stack operations, we are using C++ built in stack
        std::string ans = "";

        for (int i=0; i<s.length(); i++)
        {
            char ch = s[i];

            // If the current character is an operand, add it to our answer string.
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                ans += ch; // Append the current character of string in our answer

            // If the current character of string is an '(', push it to the stack.
            else if (ch == '(')
                st.push('(');

            // If the current character of string is an ')', append the top character of stack in our answer string
            // and pop that top character from the stack until an '(' is encountered.
            else if (ch == ')') {
                while (st.at_top() != '(')
                {
                    ans += st.at_top(); // Append the top character of stack in our answer
                    st.pull();
                }
                st.pull();
            }

            // If an operator is scanned
            else {
                while (!st.is_empty() && prec(s[i]) <= prec(st.at_top())) {
                    ans += st.at_top();
                    st.pull();
                }
                st.push(ch); // Push the current character of string in stack
            }
        }

        // Pop all the remaining elements from the stack
        while (!st.is_empty()) {
            ans += st.at_top();
            st.pull();
        }

        return ans;
    }
}