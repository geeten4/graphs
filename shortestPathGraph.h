#ifndef SHORTEST_PATH_GRAPH_H
#define SHORTEST_PATH_GRAPH_H

#include "adjacencyList.h"
#include "shortestPath.h"
#include "shortestPathList.h"
#include "minHeap.h"

/*
 * graph data structure on which the graph algorithms are implemented as methods
 */ 
namespace graph
{

class ShortestPathGraph
{

private:
    // actual graph data structure is already implemented in an AdjacencyList
    AdjacencyList<ShortestPathVertex, ShortestPathEdge> adjacencyList;

    // weight of the graph; sum of all edge weights
    float weight;

public:
    ShortestPathGraph();

    // weight handling
    float getWeight();

    /*
     * adds a new edge to the graph given the number specifying the vertices and its weight
     * @param[in] vertexNum1 number specifying the first vertex
     * @param[in] vertexNum2 number specifying the second vertex
     * @param[in] weight float weight of the edge
     */
    void addEdge(int vertexNum1, int vertexNum2, float weight);

    /*
     * prints the whole graph to the standard console
     */
    void print();

    /*
     * Dijkstras algorithm
     * @param[in] vertexNum1 number of vertex that is the origin; here our shortest path starts
     * @param[in] vertexNum2 number of vertex that is the target; here our shortest path ends
     */
    ShortestPathList* Dijkstra(int vertexNum1, int vertexNum2);

    ShortestPathGraph* minimalSpanningTree();
};

}

#endif