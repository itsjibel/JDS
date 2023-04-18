#include <stdlib.h>
#include <vector>
using std::vector;

class LL_DW
{
    private:
		struct node
		{
			int data;
			node *next;
			node *prev;
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
			n->prev = NULL;
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
					a->prev = p;
					list_size++;
					return;
				}
				p = p->next;
			}
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
				if (temp == NULL)
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
		LL_DW() {}

		LL_DW(int data)
		{
			create_node(data);
		}

		LL_DW(vector<int> values)
		{
			create_node(values.front());
			for (int i=1; i<values.size(); i++)
				append(values.at(i));
		}

		// Destructor
		virtual ~LL_DW()
		{
			free_list();
		}
};