#include <iostream>

using namespace std;

template<typename V, typename E>
AdjacencyNode<V, E>::AdjacencyNode(V* vertex)
{
    this->vertex = vertex;
    this->edgeList = LinkedList<E>();
}

template<typename V, typename E>
string AdjacencyNode<V, E>::toString()
{
    return this->vertex->toString() + ": " + this->edgeList.toString();
}

template<typename V, typename E>
void AdjacencyNode<V, E>::addEdge(E* edge)
{
    LinkedListNode<E>* node = this->edgeList.getHead();
    // check if such edge is not already in edgeList
    while(node != NULL && !node->getValue()->hasVertices(edge->getVertex1()->getNumber(), edge->getVertex2()->getNumber()))
    {
        node = node->getNext();
    }
    // if no such edge is in edgeList, node must be NULL
    if(node == NULL)
    {
        this->edgeList.add(edge);
    } else {
        cout << "Edge " + edge->toString() + " already contained in adjacencyNode." << endl;
    }
}

template<typename V, typename E>
V* AdjacencyNode<V, E>::getVertex()
{
    return this->vertex;
}

template<typename V, typename E>
LinkedList<E>* AdjacencyNode<V, E>::getEdgeList()
{
    return &this->edgeList;
}