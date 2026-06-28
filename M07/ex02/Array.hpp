#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
public:

    Array(void) : _data(NULL), _size(0) {}
    // if there is no explicit : the compiler can compile Array<int> arr = 5 
    explicit Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    Array(Array const &other) : _data(NULL), _size(0)
    {
        *this = other;
    }

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

    ~Array(void)
    {
        delete[] _data;
    }

    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Array: index out of bounds");
        return _data[index];
    }

    T const &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Array: index out of bounds");
        return _data[index];
    }

    unsigned int size(void) const
    {
        return _size;
    }

private:
    T            *_data; 
    unsigned int  _size;
};

#endif