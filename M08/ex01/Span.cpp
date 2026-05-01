#include "Span.hpp"

Span::Span(unsigned int n) : _max(n) {}

Span::Span(const Span &other) : _max(other._max), _data(other._data) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _max  = other._max;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_data.size() >= _max)
        throw std::runtime_error("Span: container is full");
    _data.push_back(n);
}

void Span::_requireSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Span: need at least 2 numbers to compute span");
}

int Span::shortestSpan() const
{
    _requireSpan();

    // Sort a copy, then find the minimum adjacent difference
    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (std::size_t i = 2; i < sorted.size(); ++i)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    _requireSpan();

    // Longest span = max element - min element
    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());
    return maxVal - minVal;
}