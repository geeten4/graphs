#include "vertex.h"
#include <iostream>

using namespace graph;

Vertex::Vertex(int number)
{
    this->number = number;
}

string Vertex::toString()
{
    return to_string(this->number);
}

int Vertex::getNumber()
{
    return this->number;
}

void Vertex::open()
{
    this->opened = true;
}

void Vertex::close()
{
    this->opened = false;
}

bool Vertex::isOpen()
{
    return this->opened;
}

bool Vertex::isVisited()
{
    return this->visited;
}

void Vertex::visit()
{
    this->visited = true;
}

void Vertex::unvisit()
{
    this->visited = false;
}
