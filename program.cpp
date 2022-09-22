#include "program.h"
#include "iostream"
#include <fstream>
#include <sstream>

void Program::start()
{
    this->graph = this->readGraphFromFile();
}

void Program::Dijkstra(int originVertexNum, int targetVertexNum)
{
    ShortestPathList* list = this->graph->Dijkstra(originVertexNum, targetVertexNum);
    list->print();
}

void Program::minimalSpanningTree()
{
    ShortestPathGraph* tree = this->graph->minimalSpanningTree();
    tree->print();
}

ShortestPathGraph* Program::readGraphFromFile()
{
    ShortestPathGraph* graph = new ShortestPathGraph();
    // read input.txt
    ifstream infile("input.txt");
    int vertexNum1, vertexNum2, edgeWeight;
    while (infile >> vertexNum1 >> vertexNum2 >> edgeWeight)
    {
        // add edges to graph
        graph->addEdge(vertexNum1, vertexNum2, edgeWeight);
    }

    infile.close();

    return graph;
}