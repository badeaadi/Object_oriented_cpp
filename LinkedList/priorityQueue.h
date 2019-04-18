#ifndef POO_PRIORITYQUEUE_H
#define POO_PRIORITYQUEUE_H
#include <algorithm>
#include "deque.h"

template<class T>
class PriorityQueue : public Deque<T> {

public:
    void push_back(const T & elem);
    PriorityQueue();
    ~PriorityQueue();

    typename Deque<T> :: Iterator begin();
    typename Deque<T> :: Iterator end();

protected:

    int mSize;
    typename Deque<T>::Iterator mStart, mEnd;
};
template<typename T>
void PriorityQueue<T>::push_back(const T &elem) {

    mSize = mSize + 1;
    if (mSize == 1) {
        DoubleNode<T> node (elem);
        mStart.setPointer(&node);
        return;
    }
    typename Deque<T>::Iterator it = this->end();
    auto * newNode = new Node<T> (elem);
    Node<T> * point = it.getPointer();

    mEnd.getPointer()->setNext(newNode);
    mEnd.setPointer(newNode);

    it = mEnd;
    while (it.getPointer()->getPriority() < mEnd.getBeforePointer().getPriority()) {
        T aux = it.getPointer()->getValue();
        it.getPointer()->setValue(it.getBeforePointer().getValue());
        it.getBeforePointer().setValue(aux);

        int auxprio = it.getPointer()->getPriority();
        it.getPointer()->setPriority(it.getBeforePointer().getPriority());
        it.getBeforePointer().setPriority(auxprio);
    }
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {

}

template<class T>
PriorityQueue<T>::PriorityQueue() {

}

template<class T>
typename Deque<T>::Iterator PriorityQueue<T>::begin() {
    return mStart;
}

template<class T>
typename Deque<T>::Iterator PriorityQueue<T>::end() {
    return mEnd;
}


#endif //POO_PRIORITYQUEUE_H
