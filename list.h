#ifndef POO_LIST_H
#define POO_LIST_H
#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace std;
#include "node.h"

template<typename T>
class List
{
public:

    List<T>(); //Standard constructor
    explicit List<T>(Node<T>);   //Constructor with one element
    List<T>(const List<T> &);   //Constructor with another list

    ~List <T>(); //Standard destructor

    int size() const;  //Size getter
    bool empty() const; //Empty verifier
    virtual void push_back(const T & elem); //Adding another element
    //void pop_back(); //Erasing the last element
    T operator [] (int index); //Returning the index of the certain element

    class Iterator{
        public:


            explicit Iterator ();
            Iterator (List<T> :: Iterator & it_new);
            explicit Iterator (const Node<T> *it);

            Iterator & operator = (const Iterator & it_new);
            bool operator == (Iterator it_new);
            bool operator != (Iterator it_new);
            Node<T> * getPointer() const;
            void setPointer(Node<T> *);

            friend ostream & operator << (ostream &out, typename List<T>::Iterator & it) {

                T newt = it.pointer->getValue();
                out << newt;
                return out;
            }
            Iterator operator ++() {
                auto it = Iterator(this->pointer->getNext());
                *this = it;
                return it;
            }
            Iterator operator ++(int) {
                List<T>::Iterator previous(*this);
                this->operator++();
                return previous;
            }
        private :

            Node<T> * pointer;

    };
    Iterator begin();
    Iterator end();

    friend ostream & operator << (ostream &out, List<T>& list) {

        for (List<int>::Iterator it = list.begin(); it.getPointer() != nullptr ; ++it)
            out << it << '\n';
        return out;
    }
    friend istream & operator >> (istream &in, List<T>& list) {

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

    delete this->pointer;
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
/*
template<typename T>
void List<T>::pop_back() {

    if (mSize == 0) {
        throw std::out_of_range("Out of bounds");
        return;
    }
    if (mSize == 1) {
        delete mStart.getPointer();
        mEnd.setPointer(nullptr);
        mStart.setPointer(nullptr);
        mSize --;
        return;
    }

    //int i  = 0;
    List<T>::Iterator it ;
    //this->begin();

    for (int i = mSize - 2; i; i--)
        ++it;
    delete mEnd.getPointer();
    mEnd.setPointer(nullptr);
    mEnd = it;
    mSize --;
}
*/
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

    /*
    for (List<T> :: Iterator it = this->begin(); it != this->end(); ++it) {

        List<T> :: Iterator it2 = it;
        delete it.getPointer();
        it = it2;
    }*/
}



#endif //POO_LIST_H
