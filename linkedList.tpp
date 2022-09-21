#include <iostream>

using namespace std;
using namespace graph;

template<typename T>
int LinkedList<T>::findValue(T* value)
{
    LinkedListNode<T>* node = this->head;
    int position = 0;
    while(node != NULL)
    {
        if(node->getValue() == value)
        {
            return position;
        }
        position++;
        node = node->getNext();
    }
    return -1;
}

template<typename T>
T* LinkedList<T>::pop()
{
    if(this->length == 0){
        return NULL;
    }
    if(this->length == 1)
    {
        LinkedListNode<T>* node = this->head;
        T* value = node->getValue();
        this->head = NULL;
        this->last = NULL;
        delete node;
        this->length--;
        return value;
    }

    LinkedListNode<T>* last = this->last;
    T* value = last->getValue();
    LinkedListNode<T>* beforeLast = this->getPosNode(this->length - 2);
    beforeLast->setNext(NULL);
    this->last = beforeLast;
    delete last;
    this->length--;
    return value;
}

template<typename T>
T* LinkedList<T>::getPosValue(int i)
{
    return this->getPosNode(i)->getValue();
}

template<typename T>
LinkedListNode<T>* LinkedList<T>::getPosNode(int i)
{
    LinkedListNode<T>* node = this->head;
    int position = 0;
    while(node != NULL && position != i)
    {
        node = node->getNext();
        position++;
    }
    return node;
}


template<typename T>
int LinkedList<T>::getLength()
{
    return this->length;
}

template<typename T>
void LinkedList<T>::add(T* value)
{
    this->length++;
    if(this->head == NULL)
    {
        LinkedListNode<T>* node = new LinkedListNode<T>(value);
        this->head = node;
        this->last = node;
    } else {
        LinkedListNode<T>* node = this->last;
        LinkedListNode<T>* newNode = new LinkedListNode<T>(value);
        node->setNext(newNode);
        this->last = newNode;
    }
}

template<typename T>
string LinkedList<T>::toString()
{
    string str = "";
    LinkedListNode<T>* node = this->head;
    while(node != NULL)
    {
        str += node->toString() + ' ';
        node = node->getNext();
    }
    return str;
}

template<typename T>
void LinkedList<T>::print()
{
    LinkedListNode<T>* node = this->head;
    while(node != NULL)
    {
        cout << node->toString() << endl;
        node = node->getNext();
    }
}

template<typename T>
LinkedListNode<T>* LinkedList<T>::getHead()
{
    return this->head;
}

template<typename T>
void LinkedList<T>::revert()
{
    // reverses the order of linked list
    for (int i = 0; i < this->length/2; i++)
    {
        this->switchNodes(i + 1, this->length - i);
    }
    
}

template<typename T>
void LinkedList<T>::switchNodes(int i, int j)
{
    // switches ith and jth nodes in list
    int min = (i < j) ? i : j;
    int max = (i > j) ? i : j;
    if(min <= 0) {
        cout << "Position " + to_string(min) + " outside of range." << endl;
        return;
    }
    if(i == j) {
        cout << "Switching same positions: " + to_string(i) << endl;
        return;
    }

    LinkedListNode<T>* node = this->head;

    int position = 1;
    LinkedListNode<T>* keepNode;
    T* switchNodeValue;
    while(node != NULL)
    {
        if(position == min)
        {
            keepNode = node;
            switchNodeValue = node->getValue();
        } else if (position == max)
        {
            keepNode->setValue(node->getValue());
            node->setValue(switchNodeValue);
            return;
        }
        position++;
        node = node->getNext();
    }

    cout << "Cannot switch positions " + to_string(i) + " and " + to_string(j) + " : list has length " + to_string(this->length) << endl;
}