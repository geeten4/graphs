#include "shortestPath.h"
#include <iostream>

using namespace graph;

ShortestPathVertex::ShortestPathVertex(int number) : Vertex(number)
{
    this->value = new ShortestPathNode();
}

void ShortestPathVertex::setShortestPathLength(float length)
{
    this->value->setShortestPathLength(length);
}

float ShortestPathVertex::getShortestPathLength()
{
    return this->value->getShortestPathLength();
}

void ShortestPathVertex::setShortestPathEdge(ShortestPathEdge* edge)
{
    this->value->setShortestPathEdge(edge);
}

ShortestPathEdge* ShortestPathVertex::getShortestPathEdge()
{
    return this->value->getShortestPathEdge();
}

namespace graph
{

bool operator==(const ShortestPathVertex &lhs, const ShortestPathVertex &rhs)
{
    return lhs.value->getShortestPathLength() == rhs.value->getShortestPathLength();
}

bool operator<(const ShortestPathVertex &lhs, const ShortestPathVertex &rhs)
{
    return lhs.value->getShortestPathLength() < rhs.value->getShortestPathLength();
}

bool operator>(const ShortestPathVertex &lhs, const ShortestPathVertex &rhs)
{
    return lhs.value->getShortestPathLength() > rhs.value->getShortestPathLength();
}

}