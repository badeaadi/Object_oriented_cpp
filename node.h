#ifndef POO_NODE_H
#define POO_NODE_H
#include <fstream>
#include <iostream>

template <class T>
class Node
{
public:
    Node();
    explicit Node(T);
    T getValue() const;
    void setValue(T);

    virtual Node<T> * getBefore();
    virtual void setBefore(Node <T> );

    Node<T> * getNext();
    void setNext(Node<T> *);
private:
    T value;
    Node<T> * next;
};

template<class T>
Node<T>::Node() {

    value = 0 ;
    next = nullptr;
}
template<class T>
Node<T>::Node(T newValue) {

    value = newValue;
    next = nullptr;
}
template<class T>
T Node<T>::getValue() const {

    return value;
}
template<class T>
Node<T> * Node<T>::getNext() {

    return next;
}

template<class T>
void Node<T>::setValue(T newVal) {

    this->value = newVal;
}

template<class T>
void Node<T>::setNext(Node<T> * pointer) {

    this->next = pointer;
}

template<class T>
Node<T> *Node<T>::getBefore() {

    throw std::out_of_range("This is not a double linked list");
}

template<class T>
void Node<T>::setBefore(Node<T>) {

    throw std::out_of_range("This is not a double linked list");
}


template <class T>
class DoubleNode : Node<T> {

    Node<T> * getBefore();
    void setBefore(Node <T> );

private:
    Node<T> * before;
};

template<class T>
Node<T> * DoubleNode<T>::getBefore() {
    return before;
}

template<class T>
void DoubleNode<T>::setBefore(Node<T> k) {

    before = k;
}





template <class T>
class PriorityNode : DoubleNode<T> {


private :
    int priority;
};

#endif //CLIONNEW_NODE_H
