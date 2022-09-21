#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "linkedListNode.h"
#include "vertex.h"
#include <iostream>

using namespace std;
using namespace graph;

namespace linked_list
{

/*
 * basic linked list for storing any type T of data
 * @tparam T type of data to be stored within a LinkedListNode node.
 *      must implement a toString() method
 */
template<typename T>
class LinkedList
{

protected:
    // first node
    LinkedListNode<T>* head = NULL;
    // last node
    LinkedListNode<T>* last = NULL;
    // length of LinkedList, the number of LinkedListNode stored.
    int length = 0;

public:
    // head handling
    LinkedListNode<T>* getHead();
    
    // length handling
    int getLength();

    /*
     * adds a new value to the linked list.
     * @param[in] value the new value to be stored. 
     */
    virtual void add(T* value);
    
    /*
     * switches two nodes inside the list
     * indexing starts at 1, e.g. switchNodes(1, this->length) switches the first and last node.
     * @param[in] i, j two distinct numbers specifying the positions of nodes to be switched
     */
    void switchNodes(int i, int j);

    /*
     * returns a LinkedListNode with the index i
     * indexing starts at 0, e.g. getPosNode(0) returns the first element.
     * @param[in] i index of node to be returned
     */
    LinkedListNode<T>* getPosNode(int i);

    /*
     * returns a T* value with the index i
     * acts like getPosNode, only then returns LinkedListNode->value
     * @param[in] i index of value to be returned
     */
    T* getPosValue(int i);

    /*
     * removes the last node in the list and returns its value.
     */
    T* pop();

    /*
     * finds a node by its T* value and returns its position as an int.
     * if no such value exists, returns NULL
     * @param[in] value the value to be found within the list
     */
    int findValue(T* value);

    /*
     * reverses the order of the list, otherwise keeps all elements intact.
     * switches only values within LinkedListNode, doest not change the order of LinkedListNodes.
     */
    void revert();


    /*
     * returns this list as a string using LinkedListNode.toString() method,
     * therefore value type T must implement a toString() method
     */
    string toString();
    
    /*
     * prints the list using this->toString() method
     */
    void print();
};

#include "linkedList.tpp"

}

#endif