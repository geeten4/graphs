#ifndef ADJACENCY_NODE
#define ADJACENCY_NODE

#include "linkedList.h"
#include <iostream>

using namespace linked_list;

namespace graph
{

/*
 * template class used within AdjacencyList to store a graph structured data
 * an AdjacencyNode stores a vertex for which all adjacent edges within a graph 
 * are stored in edgeList attribute
 * @tparam V Vertex type used in the graph
 * @tparam E Edge type used in the graph
 */
template<typename V, typename E>
class AdjacencyNode
{

private:
    // the vertex for witch incident edges are in edgeList
    V* vertex;
    // incident edges with vertex
    LinkedList<E> edgeList;

public:
    AdjacencyNode(V* vertex);

    // vertex handling
    V* getVertex();

    // edge list handling
    LinkedList<E>* getEdgeList();

    /*
     * adds an edge to edgeList
     * one of the vertices must match this->vertex->number
     * if such an edge is already contained, prints a warning message
     * @param edge the Edge to be added
     */
    void addEdge(E* edge);

    /*
     * returns this as a string in format
     * vertexNumber: edge1->toString() edge2->toString() ..
     */
    string toString();
};

#include "adjacencyNode.tpp"

}

#endif