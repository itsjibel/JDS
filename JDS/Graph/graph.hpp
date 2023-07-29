#include <iostream>

class Graph
{
private:
    typedef long long int lli;

public:
    struct Node
    {
        lli dest;
        Node* next;
    };

    struct AdjacencyList
    {
        Node* head;
    };

    lli V;
    AdjacencyList* array;

    Node* create_node(lli dest)
    {
        Node* n = new Node;
        n->dest = dest;
        n->next = NULL;
        return n;
    }

    Graph* create_graph(lli V)
    {
        Graph* g = new Graph;

        g->V = V;
        g->array = (AdjacencyList*) malloc(V * sizeof(AdjacencyList));

        for (lli i=0; i<V; i++)
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

        for (lli i=0; i<V; i++)
        {
            p = array[i].head;
            std::cout<<std::endl<<" "<<i<<" ";

            while (p)
            {
                std::cout<<" -> "<<p->dest;
                p = p->next;
            }
            std::cout<<std::endl;
        }
    }
};