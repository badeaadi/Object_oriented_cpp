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

    void push_front(const T & elem); //Adding another element

    class Iterator : public List<T>::Iterator {
    };

protected:

    int mSize{};
    Node<T> * mStart;
};

template<class T>
void Deque<T>::push_front(const T &elem) {



}

template<class T>
Deque<T>::Deque() {

}

template<class T>
Deque<T>::~Deque() {

}


template <class T>
class DequeIterator : List<T>::Iterator {

    public :
        explicit DequeIterator(const Node<T> * it_new):List<T>::Iterator(it_new)
        setBeforePointer(const Node<T> *)



    private :
};

template<class T>
DequeIterator<T>::DequeIterator(const Node<T> *it_new):List<T>::Iterator(it_new) {

    this->setPointer(const_cast<Node<T> * > (it_new));
}


template<class T>

#endif //CLIONNEW_DEQUE_H
