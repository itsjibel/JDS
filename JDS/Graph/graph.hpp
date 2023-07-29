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
    }

    lli V;
    AdjacencyList array;

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
};