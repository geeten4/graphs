#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include "adjacencyNode.h"
#include "linkedList.h"

namespace graph
{

/*
 * main part of any graph structure
 * a graph is stored as a list of AdjacencyNodes, in each AdjacencyNode a vertex and all its
 * adjacenct edges are specified, in an AdjacencyList all vertices in the graph have a 
 * AdjacencyNode with their edges
 * therefore all pointers to edges are stored twice, but searching incident edges
 * is much more convenient
 * @tparam V Vertex type to be stored
 * @tparam E Edge type to be stored
 */
template<typename V, typename E>
class AdjacencyList : public LinkedList<AdjacencyNode<V, E>>
{

public:
    /*
     * returns an AdjacencyNode from the list given the number of the vertex in the node.
     * @param[in] vertexNumber number of the vertex of which the AdjacencyNode we want
     */
    AdjacencyNode<V, E>* getAdjacencyNode(int vertexNumber);

    /*
     * adds a vertex to the list,
     * if such vertex already exists, prints a warning message
     * @param[in] vertex to be stored
     */
    void addVertex(V* vertex);

    /*
     * adds and Edge to the list
     * if any one of the vertex numbers already exist in a graph, pointer inside edge to that vertex
     * is replaced with the one vertex pointer that already exists inside the list
     */
    void addEdge(E* edge);

};

#include "adjacencyList.tpp"

}

#endif