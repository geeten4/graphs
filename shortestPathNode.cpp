#include <iostream>
#include "shortestPath.h"

using namespace graph;
using namespace std;

void ShortestPathNode::setShortestPathLength(float length)
{
    this->length = length;
}

void ShortestPathNode::setShortestPathEdge(ShortestPathEdge* edge)
{
    this->edge = edge;
}

float ShortestPathNode::getShortestPathLength()
{
    return this->length;
}

ShortestPathEdge* ShortestPathNode::getShortestPathEdge()
{
    return this->edge;
}

string ShortestPathNode::toString()
{
    return to_string(this->length);
}