#ifndef WEIGHTED_EDGE_H
#define WEIGHTED_EDGE_H

#include "edge.h"
#include "vertex.h"

namespace graph
{

/*
 * Edge child used in ShortestPathGraph, acts the same as Edge,
 * only with extra attribute weight
 * @tparam V Vertex type to be stored, just like in Edge
 */
template<typename V>
class WeightedEdge : public Edge<V>
{

private:
    float weight;

public:
    WeightedEdge(V* vertex1, V* vertex2, float weight);
    
    // weight handling, changing weight is not permitted
    float getWeight();

    /*
     * returns this as a string
     */
    string toString();

    /*
     * weighted edges can be compared by their weight,
     * overload basic comparators
     */
    template<typename T>
    friend bool operator==(const WeightedEdge<T> &lhs, const WeightedEdge<T> &rhs);
    template<typename T>
    friend bool operator<(const WeightedEdge<T> &lhs, const WeightedEdge<T> &rhs);
    template<typename T>
    friend bool operator>(const WeightedEdge<T> &lhs, const WeightedEdge<T> &rhs);
};

#include "weightedEdge.tpp"

}

#endif