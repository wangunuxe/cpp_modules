#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

// Array: a generic container class template wrapping a heap-allocated C-style array.
// Conforms to the Orthodox Canonical Form (default ctor, copy ctor, copy assignment, dtor).
// Memory is allocated with new[] and freed with delete[] to avoid leaks.
template <typename T>
class Array
{
public:

    // Default constructor: creates an empty array (size = 0, pointer = NULL)
    Array(void) : _data(NULL), _size(0) {}

    // Parameterized constructor: allocates n default-initialized elements.
    // new T[n]() uses value-initialization: 0 for POD types, default ctor for objects.
    explicit Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Copy constructor: performs a deep copy so both arrays are fully independent.
    Array(Array const &other) : _data(NULL), _size(0)
    {
        *this = other; // delegate to assignment operator
    }

    // Copy assignment operator: frees existing data, then performs a deep copy.
    // Self-assignment guard prevents freeing the source data before copying it.
    Array &operator=(Array const &other)
    {
        if (this == &other)
            return *this;

        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = other._data[i];
        return *this;
    }

    // Destructor: releases the heap-allocated array to prevent memory leaks.
    ~Array(void)
    {
        delete[] _data;
    }

    // Subscript operator (non-const version): allows read and write access.
    // Throws std::out_of_range when the index is outside [0, _size).
    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Array: index out of bounds");
        return _data[index];
    }

    // Subscript operator (const version): allows read-only access on const instances.
    // Throws std::out_of_range when the index is outside [0, _size).
    T const &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Array: index out of bounds");
        return _data[index];
    }

    // size(): returns the number of elements in the array.
    // Declared const so it can be called on const Array instances.
    unsigned int size(void) const
    {
        return _size;
    }

private:
    T            *_data; // pointer to the heap-allocated storage
    unsigned int  _size; // number of elements currently stored
};

#endif