#include <iostream>
#include <string>
#include "iter.hpp"

// --- Helper functions used as the third parameter to iter ---

// Prints any element followed by a newline (takes const ref, works for read-only arrays)
template <typename T>
void printElem(T const &elem)
{
    std::cout << elem << std::endl;
}

// Doubles a numeric element in-place (takes non-const ref, modifies array elements)
template <typename T>
void doubleElem(T &elem)
{
    elem *= 2;
}

// Appends "!" to a string in-place
void addExclamation(std::string &s)
{
    s += "!";
}

int main(void)
{
    // --- Test with int array (non-const) ---
    int intArr[] = {1, 2, 3, 4, 5};
    std::size_t intLen = 5;

    std::cout << "=== int array before doubling ===" << std::endl;
    ::iter(intArr, intLen, printElem<int>);

    ::iter(intArr, intLen, doubleElem<int>);

    std::cout << "=== int array after doubling ===" << std::endl;
    ::iter(intArr, intLen, printElem<int>);

    // --- Test with const int array (only const-compatible functions allowed) ---
    int const constArr[] = {10, 20, 30};
    std::size_t constLen = 3;

    std::cout << "=== const int array ===" << std::endl;
    ::iter(constArr, constLen, printElem<int>);

    // --- Test with std::string array ---
    std::string strArr[] = {"hello", "world", "42"};
    std::size_t strLen = 3;

    std::cout << "=== string array before modification ===" << std::endl;
    ::iter(strArr, strLen, printElem<std::string>);

    ::iter(strArr, strLen, addExclamation);

    std::cout << "=== string array after adding '!' ===" << std::endl;
    ::iter(strArr, strLen, printElem<std::string>);

    // --- Test with float array ---
    float floatArr[] = {1.1f, 2.2f, 3.3f};
    std::size_t floatLen = 3;

    std::cout << "=== float array ===" << std::endl;
    ::iter(floatArr, floatLen, printElem<float>);

    return 0;
}