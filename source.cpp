#include "source.h"
#include "iostream"

using namespace std;
using namespace linked_list;
using namespace graph;
using namespace heap;

int main()
{
    ShortestPathGraph graph = ShortestPathGraph();
    graph.addEdge(0, 1, 6);
    graph.addEdge(0, 2, 10);
    graph.addEdge(1, 2, 12);
    graph.addEdge(1, 3, 11);
    graph.addEdge(1, 4, 14);
    graph.addEdge(2, 3, 12);
    graph.addEdge(2, 6, 8);
    graph.addEdge(2, 7, 16);
    graph.addEdge(3, 5, 6);
    graph.addEdge(3, 6, 3);
    graph.addEdge(4, 5, 4);
    graph.addEdge(4, 8, 6);
    graph.addEdge(5, 8, 12);
    graph.addEdge(6, 8, 16);
    graph.addEdge(6, 9, 6);
    graph.addEdge(7, 9, 8);
    graph.addEdge(8, 9, 13);
    ShortestPathGraph* tree = graph.minimalSpanningTree();
    tree->print();
}