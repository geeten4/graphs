using namespace std;

template<typename T>
LinkedListNode<T>::LinkedListNode(T* value)
{
    this->value = value;
}

template<typename T>
void LinkedListNode<T>::setNext(LinkedListNode* next)
{
    this->next = next;
}

template<typename T>
LinkedListNode<T>* LinkedListNode<T>::getNext()
{
    return this->next;
}

template<typename T>
string LinkedListNode<T>::toString()
{
    return this->value->toString();
}

template<typename T>
T* LinkedListNode<T>::getValue()
{
    return this->value;
}

template<typename T>
void LinkedListNode<T>::setValue(T* value)
{
    this->value = value;
}