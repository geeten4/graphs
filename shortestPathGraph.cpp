#include "shortestPathGraph.h"

using namespace graph;
using namespace heap;

ShortestPathGraph::ShortestPathGraph()
{
    this->adjacencyList = AdjacencyList<ShortestPathVertex, ShortestPathEdge>();
}

float ShortestPathGraph::getWeight()
{
    return this->weight;
}

void ShortestPathGraph::addEdge(int vertexNum1, int vertexNum2, float weight)
{
    ShortestPathVertex* v1 = new ShortestPathVertex(vertexNum1);
    ShortestPathVertex* v2 = new ShortestPathVertex(vertexNum2);
    ShortestPathEdge* edge = new ShortestPathEdge(v1, v2, weight);
    this->weight += weight;
    this->adjacencyList.addEdge(edge);
}

void ShortestPathGraph::print()
{
    cout << "weight: " << to_string(this->getWeight()) << endl;
    this->adjacencyList.print();
}

ShortestPathList* ShortestPathGraph::Dijkstra(int vertexNum1, int vertexNum2)
{
    MinHeap<ShortestPathVertex> heap = MinHeap<ShortestPathVertex>();
    
    // initial vertex number
    int minVertexNum = vertexNum1;
    while(true)
    {
        // find Adjacency node given vertex number, get the Vertex object and all its incident edges in edgeList
        AdjacencyNode<ShortestPathVertex, ShortestPathEdge>* minNode = this->adjacencyList.getAdjacencyNode(minVertexNum);
        ShortestPathVertex* minVertex = minNode->getVertex();
        LinkedList<ShortestPathEdge>* edgeList = minNode->getEdgeList();

        // mark vertex as closed, we already know the shortest path
        minVertex->close();
        
        // for all adjacent edges..
        for (int i = 0; i < edgeList->getLength(); i++)
        {
            ShortestPathEdge* edge = edgeList->getPosValue(i);

            if(edge->isVisited()) {
                // handle only unvisited edges
                continue;
            }

            // vertex adjacent by the edge given
            ShortestPathVertex* vertex = edge->getOpenVertex();

            // at the end, both vertices can be closed, we can then break
            if(vertex == NULL) {
                continue;
            }

            // new smallest possible distance is given by the smallest distance to the minimal vertex
            // were using + the weight of the currently given edge
            float newSmallestDistance = minVertex->getShortestPathLength() + edge->getWeight();

            // vertex->shortestPathLength is initialized as 0, so change it either when it is 0 
            // or when the new length of the new path is less than the previously set one
            if((vertex->getShortestPathLength() == 0) || (vertex->getShortestPathLength() > newSmallestDistance))
            {
                vertex->setShortestPathLength(newSmallestDistance);
                vertex->setShortestPathEdge(edge);
            }

            // bubble the vertex up inside minimal heap
            // if the shortestPathLength has not been changed, nothing changes.
            if(vertex->isVisited()) {
                heap.bubbleUpFrom(vertex);
            } else {
                // if the vertex has not yet been visited, mark is as visited and
                // add it to the heap
                vertex->visit();
                heap.add(vertex);
            }

            // at the end mark edge as visited
            edge->visit();
        }

        // break when nothing is left in heap; the condition is at the end due to next line,
        // we want to extract the minimum and get the number of that vertex
        if(heap.getLength() == 0) {
            break;
        }

        minVertexNum = heap.extractMin()->getNumber();
    }

    // pathList represents the shortest path to the target vertex
    ShortestPathList* pathList = new ShortestPathList();
    ShortestPathVertex* vertex = this->adjacencyList.getAdjacencyNode(vertexNum2)->getVertex();

    // iteratively add edges stored in vertex->shortestPathNode->shortestPathEdge
    while(vertex->getNumber() != vertexNum1)
    {
        pathList->add(vertex->getShortestPathEdge());
        vertex = vertex->getShortestPathEdge()->getOtherVertex(vertex->getNumber());
    }
    
    // we added the edges from the end, must revert pathList
    pathList->revert();

    return pathList;
}

ShortestPathGraph* ShortestPathGraph::minimalSpanningTree()
{
    ShortestPathGraph* tree = new ShortestPathGraph();
    MinHeap<ShortestPathEdge> heap = MinHeap<ShortestPathEdge>();

    // initial vertex number
    int vertexNum = this->adjacencyList.getPosValue(0)->getVertex()->getNumber();
    while(true)
    {
        // find Adjacency node given vertex number, get the Vertex object and all its incident edges in edgeList
        AdjacencyNode<ShortestPathVertex, ShortestPathEdge>* node = this->adjacencyList.getAdjacencyNode(vertexNum);
        ShortestPathVertex* vertex = node->getVertex();
        LinkedList<ShortestPathEdge>* edgeList = node->getEdgeList();

        // mark vertex as closed, we wont visit this vertex again
        vertex->close();

        // for all adjacent edges..
        for (int i = 0; i < edgeList->getLength(); i++)
        {
            ShortestPathEdge* edge = edgeList->getPosValue(i);

            if(edge->isVisited()) {
                // handle only unvisited edges
                continue;
            }

            heap.add(edge);

            // at the end mark edge as visited
            edge->visit();
        }

        // break when nothing is left in heap; the condition is at the end due to next line,
        // we want to extract the minimum and get the number of that vertex
        if(heap.getLength() == 0) {
            break;
        }

        // find the edge with the minimum weight adjacent to the curren tree
        ShortestPathEdge* minEdge = heap.extractMin();

        // we want to extract the still open vertex, if both are closed, it means they both already
        // are in the tree, we dont need that vertex anymore
        if(minEdge->bothVerticesSameState()) {
            continue;
        }

        // if we can get a open vertex, we add the incident edge to graph and
        // carry on with this vertex
        vertex = minEdge->getOpenVertex();
        tree->addEdge(
            minEdge->getVertex1()->getNumber(),
            minEdge->getVertex2()->getNumber(),
            minEdge->getWeight()
        );
        vertexNum = vertex->getNumber();
    }

    return tree;
}