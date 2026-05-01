#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

// Find the first occurrence of 'value' in container 'c'.
// Throws std::runtime_error if not found.
template <typename T>
typename T::iterator easyfind(T &c, int value)
{
    typename T::iterator it = std::find(c.begin(), c.end(), value);
    if (it == c.end())
        throw std::runtime_error("Value not found in container");
    return it;
}

#endif