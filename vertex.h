#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

using namespace std;

namespace graph
{

/*
 * Base class for any class to be used within a graph structure
 * uniquely identifined by number
 */
class Vertex
{

protected:
    // unique identificator
    int number;

    /*
     * attributes necesary for algortihms
     * during Dijkstra, opened is true when the final distance has not 
     * yet been determined
     */ 
    bool opened = true;
    /*
     * visited is true when the vertex has been visited during BFS
     * so it is not again added to the front
     */ 
    bool visited = false;

public:
    Vertex(int number);
    int getNumber();

    // opened handling
    void open();
    void close();
    bool isOpen();

    // visited handling
    void visit();
    void unvisit();
    bool isVisited();

    /*
     * returns this vertex as a string
     */
    virtual string toString();

};

}

#endif