#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdlib.h>
#include "linkedList.h"

using namespace std;
using namespace linked_list;

namespace heap
{

/*
 * standard minimal heap, in memory stored as LinkedList
 * @tparam T type to be stored, must overload <, >, == operators
 */
template<typename T>
class MinHeap : public LinkedList<T>
{

private:
    // standard heap methods
    /*
     * standard bubble up in heap, only with specified index from where to start bubbling
     * @param[in] start Starting index inside LinkedList
     */
    void bubbleUpFrom(int start);
    void bubbleDown();

public:
    /*
     * standard bubble up only with specified T* node from where to start
     * acts just like bubbleUpFrom(int), only a with T node specified instead of int 
     */
    void bubbleUpFrom(T* startNode);

    /*
     * adds a new element to heap, the bubbles up to maintain heap structure
     * @param[in] value The value to be added
     */
    void add(T* value);

    /*
     * removes the minimum from heap, then bubbles down to maintain heap structure
     */
    T* extractMin();
};

}

#include "minHeap.tpp"

#endif