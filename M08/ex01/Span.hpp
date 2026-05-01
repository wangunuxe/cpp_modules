#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <iterator>

class Span
{
public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    // Add a single number; throws if already full
    void addNumber(int n);

    // Add a range of numbers via iterators; throws if range exceeds capacity
    template <typename Iterator>
    void addRange(Iterator first, Iterator last)
    {
        unsigned int incoming = static_cast<unsigned int>(std::distance(first, last));
        if (_data.size() + incoming > _max)
            throw std::runtime_error("Span: not enough capacity for range");
        _data.insert(_data.end(), first, last);
    }

    // Return the smallest difference between any two stored numbers
    int shortestSpan() const;

    // Return the largest difference between any two stored numbers
    int longestSpan() const;

private:
    unsigned int        _max;
    std::vector<int>    _data;

    // Helper: requires at least 2 elements, otherwise throws
    void _requireSpan() const;
};

#endif