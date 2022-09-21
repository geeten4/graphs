#include "shortestPathList.h"

using namespace graph;

float ShortestPathList::getDistance()
{
    return this->distance;
}

void ShortestPathList::setDistance(float distance)
{
    this->distance = distance;
}

void ShortestPathList::add(ShortestPathEdge* edge)
{
    this->distance += edge->getWeight();
    LinkedList::add(edge);
}