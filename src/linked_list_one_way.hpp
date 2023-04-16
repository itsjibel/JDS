#include <stdlib.h>
#include <vector>
using std::vector;

class LL_OW
{
    private:
		struct node
		{
			int data;
			struct node *next;
		};

    protected:
		struct node *start;
		int list_size = 0;

    public:
		void create_node(int val)
		{
			if (start != NULL)
				return;

			struct node *n;
			n = new(struct node);
			n->data = val;
			n->next = NULL;
			start = n;
			list_size++;
		}

		void append(int val)
		{
			if (start == NULL)
				return;
			struct node *a;
			a = new(struct node);
			a->data = val;
			a->next = NULL;
			struct node *p = start;
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

		void pop(int val)
		{
			if (start == NULL)
				return;
			struct node *p;
			p = new(struct node);
			p->data = val;
			p->next = start;
			start = p;
			list_size++;
		}

		void insert(int val, int index)
		{
			if (start == NULL || index < 0)
				return;

			struct node *i;
			i = new(struct node);
			i->data = val;
			struct node *p = start;
			struct node *temp;
			int counter=0;
			while (counter < index)
			{
				temp = p;
				p = p->next;
				if (p == NULL)
					break;
				counter++;
			}
			i->next = p;

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
			struct node *b = start, *temp;
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

		void erase(int index)
		{
			if (start == NULL || index < 0)
				return;

			struct node *d = start;
			if (index == 0)
			{
				start = d->next;
				delete d;
				list_size--;
				return;
			}
			struct node *temp;
			int counter=0;
			while(1)
			{
				if (d->next == NULL)
					return;
				if (counter == index)
				{
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

		int at(int index)
		{
			if (start == 0)
				return 0;

			struct node *p;
			int counter=0;
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

		int size()
		{
			return list_size;
		}

		void free_list()
		{
			if (start == NULL)
				return;
			struct node *d = start;
			while(1)
			{
				struct node *temp = d->next;
				if (temp == NULL)
				{
					start = NULL;
					return;
				}
				delete d;
				list_size--;
				d = temp;
			}
		}

		// Constructors
		LL_OW() {}

		LL_OW(int data)
		{
			create_node(data);
		}

		LL_OW(vector<int> values)
		{
			create_node(values.front());
			for (int i=1; i<values.size(); i++)
				append(values.at(i));
		}
};