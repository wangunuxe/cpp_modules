#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// Swap the values of two given parameters (works with any type that supports assignment)
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// Returns the smallest of two values; returns the second one if they are equal
template <typename T>
T const &min(T const &a, T const &b)
{
    return (b < a) ? b : a;
}

// Returns the greatest of two values; returns the second one if they are equal
template <typename T>
T const &max(T const &a, T const &b)
{
    return (b > a) ? b : a;
}

#endif