#include "../JDS/Graph/graph.hpp"

int main()
{
    Graph myGraph(4);
    myGraph.add_edge(0, 1);
    myGraph.add_edge(0, 2);
    myGraph.add_edge(1, 2);
    myGraph.add_edge(2, 3);

    myGraph.display_graph();
    myGraph.BFS(0);

    return 0;
}