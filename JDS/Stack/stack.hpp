#include "jmp.hpp"

template <typename T> class Stack
{
    private:
        T *stack;
        long long int _top;
        unsigned long long int capacity;

    public:
        Stack (unsigned long long int c) : capacity{c}
        {
            stack = new T[capacity];
            _top = -1;
        }

        ~Stack()
        {
            delete[] stack;
        }

        bool empty() const
        {
            return _top == -1;
        }

        bool full() const
        {
            return _top == capacity;
        }

        T push(T val)
        {
            return stack[++_top] = val;
        }

        T pull()
        {
            if (!empty())
                return stack[_top--];
            return 0;
        }

        T at(unsigned long long int i) const
        {
            return stack[i];
        }

        T top() const
        {
            return stack[_top];
        }

        unsigned long long int size() const
        {
            return capacity;
        }

        void clear()
        {
            _top = -1;
            for (int i=0; i<capacity; i++)
                stack[i] = 0;
        }

        long long int top_val()
        {
            return _top;
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
        Stack<char> st(s.size());
        std::string ans = "";

        for (int i=0; i<s.length(); i++)
        {
            char ch = s[i];

            if (ch >= '0' && ch <= '9')
            {
                while (ch >= '0' && ch <= '9')
                {
                    ans += ch;
                    if (i<s.length())
                        ch = s[++i];
                    else
                        break;
                }
                ans += '$';
            }

            if (ch == '(')
                st.push('(');
            else if (ch == ')') {
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pull();
                }
                st.pull();
            } else {
                while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                    ans += st.top();
                    st.pull();
                }
                st.push(ch);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pull();
        }
        return ans;
    }

    jmp calculate_postfix(std::string& s)
    {
        jmp a, b;
        Stack<jmp> st(s.size());
        for (unsigned long long int i=0; s[i]; ++i)
        {
            std::string number;
            while (s[i] != '$' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
                number.push_back(s[i++]);
            if (!number.empty())
                st.push(number);

            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                a = st.pull();
                b = st.pull();
                switch (s[i])
                {
                    case '+': st.push(b + a); break;
                    case '-': st.push(b - a); break;
                    case '*': st.push(b * a); break;
                    case '/': st.push(b / a); break;
                }
            }
        }
        return st.pull();
    }
}