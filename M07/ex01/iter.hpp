#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// iter: applies a function to every element of an array
// T        - element type (deduced automatically, supports both const and non-const)
// F        - callable type (function pointer, function template instantiation, etc.)
// arr      - pointer to the first element of the array
// len      - number of elements (passed as const to prevent modification)
// func     - function called on each element; may take T& or T const&
template <typename T, typename F>
void iter(T *arr, std::size_t const len, F func)
{
    for (std::size_t i = 0; i < len; ++i)
        func(arr[i]);
}

#endif