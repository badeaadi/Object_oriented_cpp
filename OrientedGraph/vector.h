
#ifndef CLIONNEW_VECTOR_H
#define CLIONNEW_VECTOR_H
#include <fstream>
#include <iostream>


template <class T>
class Vector
{
public:

    typedef T * iterator;  //Iterator of type T

    Vector<T>();   //Standard constructor

    explicit Vector(unsigned int size);  //Constructor of a certain size
    Vector<T>(const Vector<T> & v);    //Initializing the vector with another vector
    Vector<T>(unsigned int size, const T & initial);   //Initializing the vector with size elements equal to initial

    virtual ~Vector(); //Standard destructor

    unsigned int capacity() const;  //Capacity getter
    unsigned int size() const;  //Size getter
    bool empty() const; //Empty verifier
    iterator begin() const;   //Iterator begin
    iterator end() const; //Iterator end
    T & front();  //Reference to the front();
    T & back(); //Reference to the back();
    void push_back(const T & elem); //Adding another element
    void pop_back(); //Erasing the last element

    int contain(const T &elem); //Verifying the existence of a certain element
    void reserve(unsigned int capacity); //Reserving a certain capacity
    void resize(unsigned int size); //Resizing to a certain size

    T & operator[](unsigned int index); //Index operator overloading
    Vector<T> & operator=(const Vector<T> & v); //overloading the equal operator

    void sort();

protected:
    unsigned int my_size{};
    unsigned int my_capacity{};
    T * buffer;
};


template<class T>
Vector<T>::Vector() {
    my_capacity = 0;
    my_size = 0;
    buffer = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> &v)
{
    my_size = v.my_size;
    my_capacity = v.my_size;

    buffer = new T[my_size];
    for (int i  = 0 ; i < my_size; i++)
        buffer[i] = v.buffer[i];
}
template<class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T [size];
    for (int i = 0; i < size; i++)
        buffer[i] = initial;
}
template<class T>
unsigned int Vector<T>::capacity() const {
    return my_capacity;
}

template<class T>
unsigned int Vector<T>::size() const {
    return my_size;
}

template<class T>
bool Vector<T>::empty() const {
    return (my_size == 0);
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
    my_capacity = size;
    my_size = size;
    buffer = new T[size];
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin() const
{
    return buffer;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end() const
{
    return buffer + size();
}

template<class T>
T &Vector<T>::front() {

    return buffer[0];
}
template<class T>
T &Vector<T>::back() {

    return buffer[size()-1];
}

template<class T>
void Vector<T>::pop_back() {

    my_size --;
}
template<class T>
void Vector<T>::push_back(const T & elem)
{
    if (my_size >= my_capacity)
        reserve(my_capacity +5);
    buffer [my_size++] = elem;
}

template<class T>
int Vector<T>::contain(const T & elem)
{
    iterator it;
    for (it = this->begin(); it != this->end(); it++)
        if (*it == elem)
            return 1;
    return 0;
}

template <class T>
void Vector<T>::reserve(unsigned int capacity)
{
    if(buffer == 0)
    {
        my_size = 0;
        my_capacity = 0;
    }
    T * Newbuffer = new T [capacity];

    unsigned int l_Size = capacity < my_size ? capacity : my_size;

    for (unsigned int i = 0; i < l_Size; i++)
        Newbuffer[i] = buffer[i];

    my_capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}


template<class T>
void Vector<T>::resize(unsigned int size) {

    reserve(size);
    my_size = size ;
}

template<class T>
T &Vector<T>::operator[](unsigned int index) {
    return buffer[index];
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T> & v) {

    if (this == &v)
        return *this;

    my_size = v.my_size;
    my_capacity = v.my_capacity;

    delete[ ] buffer;
    buffer = new T[my_size];
    for (int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}
template<class T>
Vector<T>::~Vector()
{
    delete[]buffer;
}

template<class T>
void Vector<T>::sort() {

    int i, j;
    for (i = 0; i < my_size; i++)
        for (j = 0; j + 1 < my_size; j++)
            if (buffer[i] > buffer[i + 1]) {
                int k = buffer[i];
                buffer[i] = buffer[i + 1];
                buffer[i + 1] = k;
            }
}
#endif //CLIONNEW_VECTOR_H
