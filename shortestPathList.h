#ifndef SHORTEST_PATH_LIST_H
#define SHORTEST_PATH_LIST_H

#include "linkedList.h"
#include "shortestPath.h"

using namespace linked_list;

namespace graph
{

/*
 * a dummy data structure returned by ShortestPathGraph.shortestPath()
 * represents a path in a graph and is basically a LinkedList of ShortestPathEdge,
 * only with extra attribute distance which gives the length of the path,
 * being the sum of weights of the ShortestPathEdges inside
 */
class ShortestPathList : public LinkedList<ShortestPathEdge>
{
private:
    // length of the path
    float distance = 0;
public:
    //distnace handling
    float getDistance();
    void setDistance(float distance);
    
    /*
     * adds a new edge to the path, increases distance by the weight of the dege
     * @param[in] edge the edge to be added to the path
     */
    void add(ShortestPathEdge* edge);
};

}

#endif