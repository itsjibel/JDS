#include <stdlib.h>
#include <vector>

template <typename T> class DWLL
{
    private:
		struct node
		{
			T data;
			node *next, *prev;
		} *start;

    protected:
		unsigned long int list_size = 0;

    public:
		void create_node(T val)
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

		void append(T val)
		{
			if (start == NULL)
				return;
			node *a, *p = start;
			a = new(node);
			a->data = val;
			a->next = NULL;
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

		void pop(T val)
		{
			if (start == NULL)
				return;

			node *p;
			p = new(node);
			p->data = val;
			p->next = start;
			p->prev = NULL;
			start->prev = p;
			start = p;
			list_size++;
		}

		void insert(T val, unsigned long int index)
		{
			if (start == NULL || index < 0 || index >= list_size)
				return;

			node *i, *p = start, *temp;
			i = new(node);
			i->data = val;
			T counter=0;
			while (counter < index)
			{
				temp = p;
				p = p->next;
				if (p == NULL)
					break;
				counter++;
			}
			i->next = p;
			p->prev = i;

			if (counter == 0)
				start = i;
			else
				temp->next = i;

			list_size++;
		}

		void pop_back()
		{
			if (start == NULL)
				return;
			node *b = start, *temp;
			if (b->next == NULL)
			{
				start = NULL;
				delete b;
				list_size--;
				return;
			}

			while (1)
			{
				if (b->next == NULL)
				{
					temp->next = NULL;
					delete b;
					list_size--;
					return;
				}
				temp = b;
				b = b->next;
			}
		}

		void erase(unsigned long int index)
		{
			if (start == NULL || index < 0 || index >= list_size)
				return;

			node *d = start, *temp;
			if (index == 0)
			{
				start->next->prev = NULL;
				start = start->next;
				delete d;
				list_size--;
				return;
			}

			unsigned long int counter=0;
			while(1)
			{
				if (counter == index)
				{
					if (index != list_size - 1)
						d->next->prev = temp;
					temp->next = d->next;
					delete d;
					list_size--;
					return;
				}
				temp = d;
				d = d->next;
				counter++;
			}
		}

		void concat(DWLL &list2)
		{
			if (list2.start == NULL || start == NULL)
				return;

			node *p = start;
			while (p->next != NULL)
				p = p->next;
			p->next = list2.start;
			list2.start->prev = p;
			list_size += list2.list_size;
		}

		void reverse()
		{
			if (start == NULL)
				return;
			node *p = start, *p2, *temp;
			while (p2 != NULL)
			{
				temp = p;
				p2 = p->next;
				p->next = p->prev;
				p->prev = p2;
				p = p2;
			}
			start = temp;
		}

		T at(unsigned long int index)
		{
			if (start == NULL || index < 0 || index >= list_size)
				return 0;

			node *p;
			unsigned long int counter=0;
			for (p = start; p != NULL; p = p->next)
			{
				if (index == counter)
				{
					return p->data;
				}
				counter++;
			}

			return 0;
		}

		unsigned long int size()
		{
			return list_size;
		}

		void free_list()
		{
			if (start == NULL)
				return;

			node *d = start, *temp;
			if (d->prev != NULL)
				d->prev->next = NULL;

			while(1)
			{
				temp = d->next;
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
		DWLL() {}

		DWLL(T data)
		{
			create_node(data);
		}

		DWLL(std::vector<T> values)
		{
			create_node(values.front());
			for (T i=1; i<values.size(); i++)
				append(values.at(i));
		}

		// Destructor
		~DWLL()
		{
			free_list();
		}
};