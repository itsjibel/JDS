#include <iostream>

class Graph
{
private:
    typedef long long int lli;

    struct Node
    {
        lli dest;
        Node* next;
    };

    struct AdjacencyList
    {
        Node* head;
    };

    Node* create_node(lli dest)
    {
        Node* n = new Node;
        n->dest = dest;
        n->next = NULL;
        return n;
    }

    lli value;
    AdjacencyList* array;

public:
    Graph* create_graph(lli value)
    {
        Graph* g = new Graph;

        g->value = value;
        g->array = (AdjacencyList*) malloc(value * sizeof(AdjacencyList));

        for (lli i=0; i<value; i++)
            g->array[i].head = NULL;

        return g;
    }

    void add_edge(lli source, lli dest)
    {
        Node* n = create_node(dest);
        n->next = array[source].head;
        array[source].head = n;

        n = create_node(source);
        n->next = array[dest].head;
        array[dest].head = n;
    }

    void display_graph()
    {
        Node* p;

        for (lli i=0; i<value; i++)
        {
            p = array[i].head;
            std::cout<<" "<<i;

            while (p)
            {
                std::cout<<" -> "<<p->dest;
                p = p->next;
            }
            std::cout<<std::endl;
        }
    }
};