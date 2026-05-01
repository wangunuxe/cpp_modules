#include <iostream>
#include <string>
#include "Array.hpp"

// Helper: print all elements of an Array<T> with its size
template <typename T>
void printArray(Array<T> const &arr, std::string const &label)
{
    std::cout << label << " (size=" << arr.size() << "): [";
    for (unsigned int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i];
        if (i + 1 < arr.size())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(void)
{
    // --- Test 1: default constructor creates an empty array ---
    std::cout << "=== Test 1: default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    // --- Test 2: parameterized constructor with value-initialization ---
    std::cout << "\n=== Test 2: parameterized constructor ===" << std::endl;
    Array<int> intArr(5);
    std::cout << "intArr default values: ";
    printArray(intArr, "intArr");

    // Fill the array with values
    for (unsigned int i = 0; i < intArr.size(); ++i)
        intArr[i] = static_cast<int>(i * 10);
    printArray(intArr, "intArr after fill");

    // --- Test 3: copy constructor - deep copy (modifying copy must not affect original) ---
    std::cout << "\n=== Test 3: copy constructor (deep copy) ===" << std::endl;
    Array<int> copyArr(intArr);
    printArray(copyArr, "copyArr after copy");

    copyArr[0] = 999;
    std::cout << "After modifying copyArr[0] = 999:" << std::endl;
    printArray(intArr,  "intArr  (must be unchanged)");
    printArray(copyArr, "copyArr (modified)");

    // --- Test 4: assignment operator - deep copy ---
    std::cout << "\n=== Test 4: assignment operator (deep copy) ===" << std::endl;
    Array<int> assignArr(3);
    assignArr = intArr;
    printArray(assignArr, "assignArr after assignment");

    assignArr[1] = -1;
    std::cout << "After modifying assignArr[1] = -1:" << std::endl;
    printArray(intArr,    "intArr    (must be unchanged)");
    printArray(assignArr, "assignArr (modified)");

    // --- Test 5: out-of-bounds throws std::exception ---
    std::cout << "\n=== Test 5: out-of-bounds exception ===" << std::endl;
    try
    {
        intArr[100] = 42; // index 100 is beyond size 5
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Also test on empty array
    try
    {
        int x = empty[0];
        (void)x;
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught exception on empty: " << e.what() << std::endl;
    }

    // --- Test 6: Array<std::string> ---
    std::cout << "\n=== Test 6: Array<std::string> ===" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "hello";
    strArr[1] = "world";
    strArr[2] = "42";
    printArray(strArr, "strArr");

    Array<std::string> strCopy(strArr);
    strCopy[0] = "modified";
    printArray(strArr,  "strArr  (must be unchanged)");
    printArray(strCopy, "strCopy (modified)");

    // --- Test 7: const Array access ---
    std::cout << "\n=== Test 7: const Array ===" << std::endl;
    Array<int> const constArr(intArr);
    printArray(constArr, "constArr");
    try
    {
        int x = constArr[999];
        (void)x;
    }
    catch (std::exception const &e)
    {
        std::cout << "Caught const exception: " << e.what() << std::endl;
    }

    // --- Test 8: self-assignment guard ---
    std::cout << "\n=== Test 8: self-assignment ===" << std::endl;
    intArr = intArr; // must not crash or corrupt
    printArray(intArr, "intArr after self-assignment");

    return 0;
}