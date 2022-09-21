#include "linkedListNode.h"
#include "adjacencyList.h"
#include "adjacencyNode.h"
#include <iostream>

using namespace graph;
using namespace std;

template<typename V, typename E>
AdjacencyNode<V, E>* AdjacencyList<V, E>::getAdjacencyNode(int number)
{
    if(this->head == NULL)
    {
        return NULL;
    }

    LinkedListNode<AdjacencyNode<V, E>>* node = this->head;
    while(node != NULL)
    {
        if(node->getValue()->getVertex()->getNumber() == number)
        {
            return node->getValue();
        }
        node = node->getNext();
    }
    return NULL;
}

template<typename V, typename E>
void AdjacencyList<V, E>::addVertex(V* vertex)
{
    AdjacencyNode<V, E>* node = this->getAdjacencyNode(vertex->getNumber());
    if(node != NULL)
    {
        cout << "Vertex with number " + to_string(vertex->getNumber()) + " already exists in graph." << endl;
    }

    node = new AdjacencyNode<V, E>(vertex);
    this->add(node);
}

template<typename V, typename E>
void AdjacencyList<V, E>::addEdge(E* edge)
{
    V* v1 = edge->getVertex1();
    V* v2 = edge->getVertex2();

    if(v1->getNumber() == v2->getNumber())
    {
        cout << "Cannot add edge with matching vertices. Vertex number: " + to_string(v1->getNumber()) << endl;
        return;
    }

    AdjacencyNode<V, E>* node1 = this->getAdjacencyNode(v1->getNumber());
    AdjacencyNode<V, E>* node2 = this->getAdjacencyNode(v2->getNumber());

    // if no such vertices exist yet, add them
    // if vertices match, change pointer to them
    if(node1 == NULL) {
        this->addVertex(v1);
        node1 = this->getAdjacencyNode(v1->getNumber());
    } else {
        edge->setVertex1(node1->getVertex());
    }
    if(node2 == NULL) {
        this->addVertex(v2);
        node2 = this->getAdjacencyNode(v2->getNumber());
    } else {
        edge->setVertex2(node2->getVertex());
    }

    node1->addEdge(edge);
    node2->addEdge(edge);
}