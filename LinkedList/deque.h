#ifndef CLIONNEW_DEQUE_H
#define CLIONNEW_DEQUE_H
#include <fstream>
#include <iostream>
#include "list.h"

template<class T>
class Deque: public List<T>
{
public:

    Deque();
    ~Deque();

    virtual void push_front(const T & elem);

    virtual void push_back(const T & elem);

    class Iterator : public List<T>::Iterator {

    public :
        Iterator();
        void setPointer(Node<T> *);
        virtual void setPointer(DoubleNode<T> *);

        Iterator operator --() {
            Deque<T>::Iterator it;
            it = this->pointer->getBefore();
            *this = it;
            return it;
        }
        const Iterator operator --(int) {
            Iterator previous;
            this->operator--();
            return previous;
        }



    };
    virtual Deque<T> :: Iterator begin();
    virtual Deque<T> :: Iterator end();


private:

    int mSize;
    Iterator mStart, mEnd;
};

template<class T>
Deque<T>::Iterator::Iterator() {

}
template<class T>
void Deque<T>::Iterator::setPointer(DoubleNode<T> * it) {

    this->pointer = it;
}

template<class T>
void Deque<T>::Iterator::setPointer(Node<T> * it) {

    this->pointer = it;
}


template<class T>
Deque<T>::Deque() {

    mSize = 0;
    DoubleNode<T> *it = nullptr;
    mStart.setPointer(const_cast<DoubleNode<T> * >(it));
    mEnd.setPointer(const_cast<DoubleNode<T> * > (it));
}

template<class T>
Deque<T>::~Deque() {

}
template<typename T>
void Deque<T>::push_back(const T &elem) {

    mSize = mSize + 1;
    if (mSize == 1) {
        DoubleNode<T> node (elem);
        mStart.setPointer(&node);
        return;
    }
    Iterator it = this->end();
    auto * newNode = new Node<T> (elem);
    Node<T> * point = it.getPointer();

    mEnd.getPointer()->setNext(newNode);
    mEnd.setPointer(newNode);
}

template<class T>
void Deque<T>::push_front(const T &elem) {

    mSize ++;
    if (mSize == 1) {
        DoubleNode<T> node (elem);
        mStart.setPointer(&node);
        mEnd.setPointer(&node);
        return;
    }
    if (mSize == 2) {

        mEnd.getPointer()->setValue(elem);
        mStart.getPointer()->setNext(mEnd.getPointer());
        mEnd.getPointer()->setBefore(mStart.getPointer());
        return;
    }
    auto newDoubleNode = DoubleNode<T> (elem);
    auto it = Deque<T>::Iterator();
    mEnd.getPointer()->setNext(it.getPointer());
    it.setBeforePointer(mEnd.getPointer());
    mEnd.setPointer((it.getPointer()));
    mSize ++;
}
template<class T>
typename Deque<T>::Iterator Deque<T>::begin() {
    return mStart;
}

template<class T>
typename Deque<T>::Iterator Deque<T>::end() {

    return mEnd;
}
template<typename T>
void List<T>::pop_back() {

    if (mSize == 0) {
        throw std::out_of_range("Out of bounds");
        return;
    }
    if (mSize == 1) {
        delete mStart.getPointer();
        mEnd.setPointer(NULL);
        mStart.setPointer(NULL);
        mSize --;
        return;
    }
    List<T>::Iterator it ;
    it = this->begin();

    for (int i = mSize - 2; i; i--)
        ++it;
    delete mEnd.getPointer();
    mEnd.setPointer(nullptr);
    mEnd = it;
    mSize --;
}


#endif //CLIONNEW_DEQUE_H
