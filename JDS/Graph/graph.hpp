#include <iostream>
#include <vector>
#include <memory>

class Graph
{
private:
    typedef long long int lli;

    struct Node
    {
        lli dest;
        std::unique_ptr<Node> next;
    };

    struct AdjacencyList
    {
        std::unique_ptr<Node> head;
    };

    lli value;
    std::vector<AdjacencyList> array;

public:
    Graph(lli value) : value(value), array(value) {}

    void add_edge(lli source, lli dest)
    {
        std::unique_ptr<Node> n = std::make_unique<Node>();
        n->dest = dest;
        n->next = std::move(array[source].head);
        array[source].head = std::move(n);

        n = std::make_unique<Node>();
        n->dest = source;
        n->next = std::move(array[dest].head);
        array[dest].head = std::move(n);
    }

    void display_graph()
    {
        for (lli i = 0; i < value; i++)
        {
            std::cout << " " << i;

            Node* p = array[i].head.get();
            while (p)
            {
                std::cout << " -> " << p->dest;
                p = p->next.get();
            }
            std::cout << std::endl;
        }
    }
};