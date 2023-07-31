#include <iostream>
#include <vector>
#include <memory>
#include "../Queue/Circular-Queue/circular-queue.hpp"
#include "../Stack/stack.hpp"

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

    lli V;
    std::vector<AdjacencyList> array;

public:
    Graph(lli V) : V(V), array(V) {}

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
        std::vector<bool> visited(V, false);
        CQueue<lli> q(V);

        visited[source] = true;
        q.push(source);

        while (!q.empty())
        {
            lli node = q.front();
            std::cout << node << " ";
            q.pop();

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

            for (lli neighbor : neighbors)
                if (!q.push(neighbor))
                    break;
        }
        std::cout << std::endl;
    }

    void display_graph()
    {
        for (lli i = 0; i < V; i++)
        {
            std::cout << i;
            Node* p = array[i].head.get();
            while (p)
            {
                std::cout << " -> " << p->dest;
                p = p->next.get();
            }
            std::cout << std::endl;
        }
    }

    void DFS(lli source)
    {
        std::vector<bool> visited(V, false);
        DFSUtil(source, visited);
        std::cout << std::endl;
    }

    void shortest_path(lli source, lli dest)
    {
        std::vector<bool> visited(V, false);
        std::vector<lli> parent(V, -1);
        CQueue<lli> q(V);

        visited[source] = true;
        q.push(source);

        while (!q.empty())
        {
            lli node = q.pop();

            Node* p = array[node].head.get();
            while (p)
            {
                lli neighbor = p->dest;
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
                p = p->next.get();
            }
        }

        if (!visited[dest])
        {
            std::cout<<"No path from "<<source<<" to "<<dest<<" exists."<<std::endl;
            return;
        }

        std::cout<<"Shortest path from "<<source<<" to "<<dest<<": ";
        Stack<lli> path(V);
        lli current = dest;
        while (current != -1)
        {
            path.push(current);
            current = parent[current];
        }

        while (!path.empty())
            std::cout<<path.pop()<<(!path.empty() ? " -> " : "");

        std::cout<<std::endl;
    }

private:
    void DFSUtil(lli node, std::vector<bool>& visited)
    {
        visited[node] = true;
        std::cout<<node<<" ";

        Node* p = array[node].head.get();
        while (p)
        {
            lli neighbor = p->dest;
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);

            p = p->next.get();
        }
    }
};