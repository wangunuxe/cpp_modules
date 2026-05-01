#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

// MutantStack wraps std::stack and exposes iterators
// by reaching into the underlying container (std::stack::c).
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &other)
    {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    // Expose the iterator types of the underlying container.
    // std::stack uses std::deque by default; 'c' is the protected member.
    typedef typename std::stack<T>::container_type::iterator       iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end();   }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end();   }
};

#endif