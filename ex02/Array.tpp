#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array(): _start(new T[0]()), _size(0) {}


template<typename T>
Array<T>::Array(unsigned int size): _start(new T[size]()), _size(size) {}

template<typename T>
Array<T>::Array(const Array& other) : _start(new T[other.size()]()), _size(other.size()){
    for (size_t i = 0; i < other.size(); i++)
    {
        this->_start[i] = other._start[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other)
    {
        delete[] _start;
        this->_size = other._size;
        _start = new T[_size]();
        for (size_t i = 0; i < _size; i++)
        {
            this->_start[i] = other._start[i];
        }
    }
    return *this;
    
}

template<typename T>
Array<T>::~Array(){
    delete[] _start;
}

template<typename T>
T& Array<T>::operator[](unsigned int i){
    if (i >= _size)
    {
        throw OutOfBoundsException();
    }
    return _start[i];
}
template<typename T>
const T& Array<T>::operator[](unsigned int i) const{
    if (i >= _size)
    {
        throw OutOfBoundsException();
    }
    return _start[i];
}


template<typename T>
unsigned int Array<T>::size() const{
    return _size;
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw(){
    return "Error: Index is out of bounds!";
}
#endif