#ifndef SHORTEST_PATH_EDGE
#define SHORTEST_PATH_EDGE

#include "weightedEdge.h"

namespace graph
{

/*
 * a special Vertex and Edge are defined here, they all must be inside the same
 * due to cross references
 */

class ShortestPathEdge;

/*
 * a dummy data structure used in Dijkstra algortihm
 * always stored inside a Vertex
 * stores the current shortest known path to the given vertex
 * and the last edge of that path
 */
class ShortestPathNode
{
private:
    /* shortest distance knowkn during Dijkstra
     * when minimal, then denotes the minimal distance between two vertices
     */ 
    float length = 0;
    // last edge of the given path
    ShortestPathEdge* edge = NULL;

public:
    // length handling
    float getShortestPathLength();
    void setShortestPathLength(float length);
    
    // edge handling
    ShortestPathEdge* getShortestPathEdge();
    void setShortestPathEdge(ShortestPathEdge* edge);
    
    /*
     * returns this as a string
     */
    string toString();

};

/*
 * a special vertex type used in Dijkstra algorithm
 * in addition to being a vertex stores a ShortestPathNode value, which during
 * Dijkstra captures the length of the currently known shortest path and a
 * pointer to the edge that is the last in that path; from this edge then the
 * shortest actual path can be reconstructed
 */
class ShortestPathVertex : public Vertex
{

private:
    // dummy data structure
    ShortestPathNode* value;

public:
    ShortestPathVertex(int number);

    // value handling
    void setShortestPathLength(float length);
    float getShortestPathLength();

    /*
     * sets shortestPathEdge inside this->value
     * @param[in] edge the edge to be stored
     */
    void setShortestPathEdge(ShortestPathEdge* edge);

    /*
     * returns edge stored inside the ShortestPathNode this->value
     */
    ShortestPathEdge* getShortestPathEdge();

    /*
     * during dijkstra, vertices are order in a minimal heap and selected by their 
     * currenty known minimal distance from the origin, therefore we need to overload
     * these operators for ShortestPathVertex to be stored in a minHeap
     */
    friend bool operator==(const ShortestPathVertex &lhs, const ShortestPathVertex &rhs);
    friend bool operator<(const ShortestPathVertex &lhs, const ShortestPathVertex &rhs);
    friend bool operator>(const ShortestPathVertex &lhs, const ShortestPathVertex &rhs);
};

/*
 * edge type used in Dijkstra algorithm
 * only a shortcut just so we dont have to specify WeightedEdge<ShortestPathVertex> everywhere
 */
class ShortestPathEdge : public WeightedEdge<ShortestPathVertex>
{
public:
    ShortestPathEdge(ShortestPathVertex* v1, ShortestPathVertex* v2, float weight);
};

}

#endif