#include "source.h"
#include "iostream"

using namespace std;
using namespace linked_list;
using namespace graph;
using namespace heap;

/*
 * simple graph algorithm library
 * implemented the Dijsktra algortihm and Minimal spanning tree algorithm
 * to create a graph, use ShortestPathGraph instance
 * to add an edge to the graph, on this instance use the addEdge(int, int, float) method
 * a vertex is uniquely defined by its number
 * addEdge(vertex number, vertex number, weight of the edge between these two vertices)
 * Dijsktra algortihm under Dijsktra(int, int) method
 * minimal spanning tree algorithm under minimalSpanningTree() method
 * 
 * for visualization use for example https://graphonline.ru/en/?graph=weightedGraph
 */

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
    
    // ShortestPathGraph* tree = graph.minimalSpanningTree();
    // tree->print();
    
    ShortestPathList* list = graph.Dijkstra(0, 9);
    list->print();
}