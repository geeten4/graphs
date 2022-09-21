#ifndef EDGHE_H
#define EDGHE_H

#include <iostream>

using namespace std;

namespace graph
{

/*
 * base for any class to be used as an edge within a graph structure
 * stores two different vertex pointers
 * @tparam V the type of Vertex to be stored within an edge
 */

template<typename V>
class Edge
{
protected:
    V* vertex1;
    V* vertex2;

    // necessary for algortihms
    bool visited = false;

public:
    Edge(V* vertex1, V* vertex2);

    // vertex1 and vertex2 handling
    void setVertex1(V* value);
    void setVertex2(V* value);
    V* getVertex1();
    V* getVertex2();

    // visited handling
    bool isVisited();
    void visit();
    void unvisit();

    /*
     * returns true if bothe vertices are in the same state; e.g. both open / both closed
     */
    bool bothVerticesSameState();

    /*
     * returns true if the numbers in vertex1 and vertex2 are vertexNum1 and vertexNum2
     * order does not matter
     * @param[in] vertexNum1 first vertex number to be compared
     * @param[in] vertexNum2 second vertex number to be compared
     */
    bool hasVertices(int vertexNum1, int vertexNum2);

    /*
     * when BFS, we want to select the vertex which is not open yet
     * checks whether only one vertex is closed and returns the second one
     * if both are in the same state returns NULL
     */
    V* getOpenVertex();

    /*
     * acts exactly the same as getOpenVertex, only returns the closed vertex
     */
    V* getClosedVertex();

    /*
     * returns the other vertex than the one specified by vertexNum
     * @param[in] vertexNum number of the vertex NOT to be returned
     */
    V* getOtherVertex(int vertexNum);

    /*
     * returns this edge as a string
     */
    virtual string toString();
};

#include "edge.tpp"

}

#endif