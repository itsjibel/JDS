#include <stdio.h>
#include <vector>
using std::vector;

template <typename T> class COWLL
{
    public:
		unsigned long int list_size = 0;

		struct node
		{
			T data;
			node *next, *prev;
		} *start;

        void create_node(T val)
		{
			if (start != NULL)
				return;

			node *n;
			n = new(node);
			n->data = val;
			n->next = n;
			start = n;
			list_size++;
		}

		void append(T val)
		{
			if (start == NULL)
				return;
			node *a;
			a = new(node);
			a->data = val;
			a->next = start;
			node *p = start;
			while(1)
			{
				if (p->next == start)
				{
					p->next = a;
					list_size++;
					return;
				}
				p = p->next;
			}
		}

		void pop(T val)
		{
			if (start == NULL)
				return;

			node *p, *l=start;
			p = new(node);
			p->data = val;
			p->next = start;
			while (l->next != start)
				l = l->next;
			l->next = p;
			start = p;
			list_size++;
		}

		void insert(T val, unsigned long int index)
		{
			if (start == NULL || index < 0 || index > list_size)
				return;

			node *i;
			i = new(node);
			i->data = val;
			node *p = start, *temp;
			unsigned long int counter=0;
			while (counter < index)
			{
				temp = p;
				p = p->next;
				if (p == start)
					break;
				counter++;
			}
			i->next = p;

			if (counter == 0)
			{
				node *l;
				while (l->next != start)
					l = l->next;
				l->next = i;
				start = i;
			}
			else
				temp->next = i;

			list_size++;
		}

		void pop_back()
		{
			if (start == NULL)
				return;
			node *b = start, *temp;

			while (1)
			{
				if (b->next == start)
				{
					if (b == start)
						start = NULL;
					temp->next = start;
					list_size--;
					delete b;
					return;
				}
				temp = b;
				b = b->next;
			}
		}

		void erase(unsigned long int index)
		{
			if (start == NULL || index < 0)
				return;

			node *d = start;
			if (index == 0)
			{
				node *l=start;
				while (l->next != start)
					l = l->next;
				l->next = d->next;
				start = d->next;
				list_size--;
				delete d;
				return;
			}

			node *temp;
			unsigned long counter=0;
			while(1)
			{
				if (counter == index)
				{
					if (d->next == start)
						temp->next = start;
					temp->next = d->next;
					list_size--;
					delete d;
					return;
				}
				temp = d;
				d = d->next;
				counter++;
				if (d == start)
					return;
			}
		}

		node *break_list()
		{
			node *new_head;
			if (start == NULL || list_size == 1)
				return NULL;

			node *p1 = start, *p2 = start;
			while (p2->next != start)
			{
				if (p2->next->next != start)
				{
					p2 = p2->next->next;
					p1 = p1->next;
				} else if (p2->next != start) {
					p2 = p2->next;
				}
			}
			
			new_head = p1->next;
			p2->next = new_head;
			p1->next = start;

			return new_head;
		}

        T at(unsigned long int index)
		{
			if (start == NULL || index < 0 || index >= list_size)
				return 0;

			node *p = start;
            if (index == 0)
                return p->data;
            else {
                while (p->next != start)
                {
                    if (index == 0)
                    {
                        return p->data;
                    }
					p = p->next;
                    index--;
                }
				return p->data;
            }

			return 0;
		}

        T size()
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

		COWLL(T data)
		{
			create_node(data);
		}

		COWLL(vector<T> values)
		{
			create_node(values.front());
			for (T i=1; i<values.size(); i++)
				append(values.at(i));
		}

		// Destructor
		virtual ~COWLL()
		{
			free_list();
		}
};