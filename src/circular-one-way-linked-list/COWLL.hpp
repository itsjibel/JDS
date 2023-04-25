#include <stdlib.h>
#include <vector>
using std::vector;

class COWLL
{
    private:
		struct node
		{
			int data;
			node *next, *prev;
		} *start;

    protected:
		int list_size = 0;

    public:
        void create_node(int val)
		{
			if (start != NULL)
				return;

			node *n;
			n = new(node);
			n->data = val;
			n->next = NULL;
			start = n;
			list_size++;
		}

		void append(int val)
		{
			if (start == NULL)
				return;
			node *a;
			a = new(node);
			a->data = val;
			a->next = NULL;
			node *p = start;
			while(1)
			{
				if (p->next == NULL)
				{
					p->next = a;
					list_size++;
					return;
				}
				p = p->next;
			}
		}

        int at(int index)
		{
			if (start == NULL || index < 0 || index >= list_size)
				return 0;

			node *p = start;
            if (index == 0)
                return p->data;
            else {
                int counter=0;
                for (; p->next != start; p = p->next)
                {
                    if (index == counter)
                    {
                        return p->data;
                    }
                    counter++;
                }
            }

			return 0;
		}

        int size()
		{
			return list_size;
		}

        void free_list()
		{
			if (start == NULL)
				return;
			node *d = start;
			while(1)
			{
				node *temp = d->next;
				if (temp != start)
				{
					start = NULL;
					return;
				}
				delete d;
				list_size--;
				d = temp;
			}
			start = NULL;
		}

		// Constructors
		COWLL() {}

		COWLL(int data)
		{
			create_node(data);
		}

		COWLL(vector<int> values)
		{
			create_node(values.front());
			for (int i=1; i<values.size(); i++)
				append(values.at(i));
		}

		// Destructor
		virtual ~COWLL()
		{
			free_list();
		}
};