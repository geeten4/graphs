using namespace heap;

template<typename T>
void MinHeap<T>::add(T* value)
{
    LinkedList<T>::add(value);
    this->bubbleUpFrom(this->length);
}

template<typename T>
void MinHeap<T>::bubbleUpFrom(T* startNode)
{
    int start = this->findValue(startNode);
    this->bubbleUpFrom(start);
}

template<typename T>
void MinHeap<T>::bubbleUpFrom(int i)
{
    T value = *this->last->getValue();
    while(i > 1)
    {
        if(*this->getPosValue(i/2 - 1) > value)
        {
            this->switchNodes(i/2, i);
            i /= 2;
        } else {
            break;
        }
    }
}

template<typename T>
void MinHeap<T>::bubbleDown()
{
    int i = 1;
    T value = *this->head->getValue();
    while(2*i <= this->length)
    {
        if(2*i == this->length)
        {
            if(value > *this->getPosValue(2*i - 1)) {
                this->switchNodes(i, 2*i);
            }
            break;
        } else {
            int minIndex = *this->getPosValue(2*i - 1) < *this->getPosValue(2*i) ? 2*i - 1 : 2*i;
            if(value > *this->getPosValue(minIndex)) {
                this->switchNodes(i, minIndex + 1);
            }
            i = minIndex + 1;
        }
    }
}

template<typename T>
T* MinHeap<T>::extractMin()
{
    T* minimum;
    if(this->length > 1)
    {
        this->switchNodes(1, this->length);
        minimum = this->pop();
        this->bubbleDown();
    } else {
        minimum = this->pop();
    }
    return minimum;
}
