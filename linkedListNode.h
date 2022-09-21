#ifndef LINKED_LIST_NODE
#define LINKED_LIST_NODE

#include <iostream>

using namespace std;

namespace linked_list
{

/*
 * node used in LinkedList 
 * stores on piece of data and refers to the next LinkedListNode in a linked list.
 * @tparam T type of data to be stored, T must have a method toString()
 */
template<typename T>
class LinkedListNode
{

protected:
    // pointer to data stored
    T* value;
    // points to the next node in a linked list
    LinkedListNode* next = NULL;

public:
    LinkedListNode(T* value);

    // value handling
    T* getValue();
    void setValue(T* value);

    // next handling
    void setNext(LinkedListNode* next);
    LinkedListNode* getNext();
    
    /*
     * returns this as a string using this->value->toString(),
     * which must be implemented
     */
    string toString();
};

#include "linkedListNode.tpp"

}

#endif