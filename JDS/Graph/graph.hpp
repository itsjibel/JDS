#include <iostream>
#include <vector>
#include <memory>
#include "../Queue/Circular-Queue/circular-queue.hpp"
#include <queue>
#include <algorithm>

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

    void BFS(lli source)
    {
        std::vector<bool> visited(value, false);
        CQueue<lli> q(12);

        visited[source] = true;
        q.push(source);

        while (!q.empty())
        {
            lli node = q.front();
            std::cout << node << " ";
            q.pop();

            // Store adjacent nodes in a vector
            std::vector<lli> neighbors;
            Node* p = array[node].head.get();
            while (p)
            {
                lli neighbor = p->dest;
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    neighbors.push_back(neighbor);
                }
                p = p->next.get();
            }

            // Sort the neighbors
            std::sort(neighbors.begin(), neighbors.end());

            // Enqueue sorted neighbors into the queue
            for (lli neighbor : neighbors)
            {
                if (!q.push(neighbor)) // Handle the return value of push()
                    break;
            }
        }
        std::cout << std::endl;
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