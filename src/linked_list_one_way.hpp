#include <iostream>
using std::cout;

class List
{
    private:
	struct node
	{
		int data;
		struct node *next;
	};

    protected:
	struct node *start;

    public:
	void create_node(int val)
	{
		struct node *n;
		n = new(struct node);
		n->data = val;
		n->next = NULL;
		start = n;   
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
	}

	void insert(int val, int index)
	{
	    if (start == NULL)
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
	    	return;
	    }

	    while (1)
	    {
			if (b->next == NULL)
			{
				temp->next = NULL;
				delete b;
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
				return;
			}
			temp = d;
			d = d->next;
			counter++;
	    }
	}

	void show()
	{
	    if (start == NULL)
			return;
	    struct node *p = start;
	    while(1)
	    {
	        cout<<p->data<<'\n';
	        if(p->next == NULL)
	            return;
			p = p->next;
	    }
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
			d = temp;
	    }
	}
};