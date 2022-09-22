#ifndef PROGRAM_H
#define PROGRAM_H

#include "shortestPathGraph.h"

/*
 * main class handling the whole program
 */
class Program
{
private:
    ShortestPathGraph* graph;
public:
    // starts the program
    void start();

    // reads a graph given in the "input.txt" file
    ShortestPathGraph* readGraphFromFile();

    // runs the dijkstra algorithm
    void Dijkstra(int originVertexNum, int targetVertexNum);

    // runs the minimal spanning tree algortihm
    void minimalSpanningTree();
};

#endif