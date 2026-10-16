#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>
#include <ctime>

template<typename T>
class Array 
{
private:
    T* _start;
    unsigned int _size;

    
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int i);
    const T& operator[](unsigned int i) const;

    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

};

#include "Array.tpp"

#endif