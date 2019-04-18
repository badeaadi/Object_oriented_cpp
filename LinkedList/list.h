#ifndef POO_LIST_H
#define POO_LIST_H
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "node.h"

template<typename T>
class List
{
public:

    List<T>(); //Standard constructor
    explicit List<T>(Node<T>);   //Constructor with one element
    List<T>(const List<T> &);   //Constructor with another list

    virtual ~List <T>(); //Standard destructor

    int size() const;  //Size getter
    bool empty() const; //Empty verifier
    virtual void push_back(const T & elem); //Adding another element
    void pop_back(); //Erasing the last element
    T operator [] (int index); //Returning the index of the certain element

    class Iterator{
        public:


            explicit Iterator ();
            Iterator (List<T> :: Iterator & it_new);
            explicit Iterator (const Node<T> *it);
            explicit Iterator (const DoubleNode<T> *it);


            Iterator & operator = (const Iterator & it_new);
            virtual bool operator == (Iterator it_new);
            virtual bool operator != (Iterator it_new);
            Node<T> * getPointer() const;
            virtual void setPointer(Node<T> *);
            virtual void setPointer(DoubleNode<T> *);

            virtual Node<T>  getBeforePointer() const;
            virtual void setBeforePointer(const Node<T> *);

            friend std::ostream & operator << (std::ostream &out, typename List<T>::Iterator & it) {

                T newt = it.pointer->getValue();
                out << newt;
                return out;
            }
            Iterator operator ++() {
                auto it = Iterator(this->pointer->getNext());
                *this = it;
                return it;
            }
            const Iterator operator ++(int) {
                List<T>::Iterator previous;
                previous = *this;
                *this = this->operator++();
                return previous;
            }
        protected:

            Node<T> * pointer;

    };
    Iterator begin();
    Iterator end();

    friend std::ostream & operator << (std::ostream &out, List<T>& list) {

        for (List<int>::Iterator it = list.begin(); it.getPointer() != nullptr ; ++it)
            out << it << '\n';
        return out;
    }
    friend std::istream & operator >> (std::istream &in, List<T>& list) {

        int n;
        in >> n;
        T p;
        for (; n; n--) {
            in >> p;
            list.push_back(p);
        }
        return in;
    }

protected:

    int mSize;
    Iterator mStart, mEnd;
};

template <typename T>
List<T>::Iterator::Iterator() {

    this->pointer = nullptr;
}

template <typename T>
List<T>::Iterator::Iterator(List<T> :: Iterator & it_new) {

    this->setPointer(it_new.getPointer());
}
template <typename T>
List<T>::Iterator::Iterator(const Node<T> * it_new) {

    this->setPointer(const_cast<Node<T> * >(it_new));
}

template <typename T>
typename List<T>::Iterator & List<T>::Iterator::operator = (const Iterator & it_new) {

    this->pointer = it_new.pointer;
    return *this;
}

template<typename T>
bool List<T>::Iterator::operator==(List<T>::Iterator it_new) {

    return (this->pointer == it_new.pointer);
}

template<typename T>
bool List<T>::Iterator::operator!=(List<T>::Iterator it_new) {

    return (this->pointer != it_new.pointer);
}

template<typename T>
Node<T> * List<T>::Iterator::getPointer() const {
    return pointer;
}

template<typename T>
void List<T>::Iterator::setPointer(Node<T> * newPointer) {

    this->pointer  = newPointer;
}

template<typename T>
Node<T> List<T>::Iterator::getBeforePointer() const {

    throw::std::out_of_range("Out of bounds");
}

template<typename T>
void List<T>::Iterator::setBeforePointer(const Node<T> *) {

    throw::std::out_of_range("Out of bounds");
}

template<typename T>
List<T>::Iterator::Iterator(const DoubleNode<T> *it) {

    this->setPointer(it);
}

template<typename T>
void List<T>::Iterator::setPointer(DoubleNode<T> * newPointer) {

    this->setPointer(newPointer);
}
template<typename T>
typename List<T>::Iterator List<T>::begin() {

    return mStart;
}

template<typename T>
typename List<T>::Iterator List<T>::end(){

    return mEnd;
}

template<typename T>
List<T>::List () {

    mSize = 0;
}
template<typename T>
List<T>::List (Node<T> firstNode) {

    mStart = firstNode;
    mSize = 1;
}
template<class T>
List<T>::List (const List<T> & secondList) {

    mSize = secondList.mSize;
    for (int i = 0; i < secondList.size(); i++)
        this->push_back(secondList[i]);
}
template<class T>
int List<T>::size() const {

    return mSize;
}
template<class T>
bool List<T>::empty() const {

    return size() == 0;
}

template<typename T>
void List<T>::push_back(const T &elem) {

    mSize = mSize + 1;
    if (mSize == 1) {
        Node<T> newNode(elem);
        mStart.setPointer(&newNode);
        mEnd.setPointer(&newNode);
        return;
    }
    Iterator it = this->end();
    auto * newNode = new Node<T> (elem);
    Node<T> * point = it.getPointer();

    mEnd.getPointer()->setNext(newNode);
    mEnd.setPointer(newNode);
}
template<typename T>
T List<T>::operator[](int index) {

    if (index >= mSize) {
        throw std::out_of_range("Out of bounds");
        return 0;
    }
    List<T> :: Iterator it = this->begin();
    while (index--)
        it ++;
    return it.pointer->getValue();
}

template<typename T>
List<T>::~List<T>() {

    for (List<T> :: Iterator it = this->begin(); it != this->end(); ++it) {
        List<T> :: Iterator it2 = it;
        delete it.getPointer();
        it = it2;
    }
}
#endif //POO_LIST_H
