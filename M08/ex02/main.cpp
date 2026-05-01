#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

int main()
{
    // --- Subject example with MutantStack ---
    std::cout << "=== MutantStack ===" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;  // 17
        mstack.pop();
        std::cout << mstack.size() << std::endl; // 1

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it  = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        // Verify that MutantStack is copy-constructible into std::stack
        std::stack<int> s(mstack);
        std::cout << "std::stack size after copy: " << s.size() << std::endl;
    }

    // --- Same logic with std::list for comparison ---
    std::cout << "\n=== std::list (same logic) ===" << std::endl;
    {
        std::list<int> lst;

        lst.push_back(5);
        lst.push_back(17);

        std::cout << lst.back() << std::endl;  // 17
        lst.pop_back();
        std::cout << lst.size() << std::endl;  // 1

        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::list<int>::iterator it  = lst.begin();
        std::list<int>::iterator ite = lst.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    // --- Extra: const iterator test ---
    std::cout << "\n=== Const iterator test ===" << std::endl;
    {
        MutantStack<int> ms;
        ms.push(10);
        ms.push(20);
        ms.push(30);

        const MutantStack<int> &cms = ms;
        MutantStack<int>::const_iterator cit = cms.begin();
        while (cit != cms.end())
        {
            std::cout << *cit << std::endl;
            ++cit;
        }
    }

    return 0;
}