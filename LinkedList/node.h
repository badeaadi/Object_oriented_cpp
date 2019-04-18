#ifndef POO_NODE_H
#define POO_NODE_H
#include <fstream>
#include <iostream>


//Node class template

template <class T>
class Node
{
public:
    Node();
    explicit Node(T);
    T getValue() const;
    void setValue(T);

    Node<T> * getNext();
    void setNext(Node<T> *);

    virtual Node<T> * getBefore();
    virtual void setBefore(Node <T> * );

    virtual int getPriority();
    virtual void setPriority(int);

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
void Node<T>::setBefore(Node<T> *) {

    throw std::out_of_range("This is not a double linked list");
}

template<class T>
int Node<T>::getPriority() {
    return 0;
}
template<class T>
void Node<T>::setPriority(int ) {

}

//Double Node class template

template <class T>
class DoubleNode : public Node<T> {

public :
    DoubleNode();
    DoubleNode(const T &);

    Node<T> * getBefore();
    void setBefore(DoubleNode <T> * );

private:
    Node<T> * before;
};

template<class T>
Node<T> * DoubleNode<T>::getBefore() {
    return before;
}

template<class T>
void DoubleNode<T>::setBefore(DoubleNode<T> * k) {

    before = k;
}

template<class T>
DoubleNode<T>::DoubleNode() {

    this->value = 0;
    this->next = nullptr;

}

template<class T>
DoubleNode<T>::DoubleNode(const T & value) {

    this->setValue(value);
    this->setNext(nullptr);

}


//Priority Node class template
template <class T>
class PriorityNode : DoubleNode<T> {

    int getPriority();
    void setPriority(int prio);

private :
    int priority;
};

template<class T>
int PriorityNode<T>::getPriority() {

    return priority;
}

template<class T>
void PriorityNode<T>::setPriority(int prio) {

    priority = prio;
}

#endif //CLIONNEW_NODE_H
