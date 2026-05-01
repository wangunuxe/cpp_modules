#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
    // --- Test with int ---
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    // --- Test with std::string ---
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    // --- Test with float ---
    float x = 1.5f;
    float y = 1.5f;

    std::cout << "min( x, y ) [equal] = " << ::min(x, y) << std::endl; // should return y (second)
    std::cout << "max( x, y ) [equal] = " << ::max(x, y) << std::endl; // should return y (second)

    return 0;
}