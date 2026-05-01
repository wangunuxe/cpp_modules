#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    // --- Subject example ---
    std::cout << "=== Subject example ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 2
        std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl; // 14
    }

    // --- Exception: too many elements ---
    std::cout << "\n=== Overflow exception ===" << std::endl;
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        try {
            sp.addNumber(4); // should throw
        } catch (std::exception &e) {
            std::cerr << "Caught: " << e.what() << std::endl;
        }
    }

    // --- Exception: not enough elements ---
    std::cout << "\n=== Too few elements exception ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(42);
        try {
            sp.shortestSpan(); // should throw
        } catch (std::exception &e) {
            std::cerr << "Caught: " << e.what() << std::endl;
        }
    }

    // --- Large test with addRange (10,000 numbers) ---
    std::cout << "\n=== Large test: 10,000 random numbers ===" << std::endl;
    {
        std::srand(42);
        Span big(10000);

        std::vector<int> nums;
        nums.reserve(10000);
        for (int i = 0; i < 10000; ++i)
            nums.push_back(std::rand());

        big.addRange(nums.begin(), nums.end());

        std::cout << "shortestSpan: " << big.shortestSpan() << std::endl;
        std::cout << "longestSpan:  " << big.longestSpan()  << std::endl;
    }

    // --- addRange overflow ---
    std::cout << "\n=== addRange overflow exception ===" << std::endl;
    {
        Span sp(3);
        std::vector<int> v;
        v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4);
        try {
            sp.addRange(v.begin(), v.end()); // should throw
        } catch (std::exception &e) {
            std::cerr << "Caught: " << e.what() << std::endl;
        }
    }

    return 0;
}