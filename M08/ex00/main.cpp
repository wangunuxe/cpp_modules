#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    // --- Test with std::vector ---
    std::cout << "=== std::vector ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(42);
    vec.push_back(7);
    vec.push_back(99);

    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found 42 at index "
                  << std::distance(vec.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(vec, 100); // should throw
        std::cout << "Found 100 (unexpected)" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- Test with std::list ---
    std::cout << "\n=== std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found 20: *it = " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- Test with std::deque ---
    std::cout << "\n=== std::deque ===" << std::endl;
    std::deque<int> dq;
    dq.push_back(5);
    dq.push_back(15);
    dq.push_back(25);

    try {
        easyfind(dq, 999); // should throw
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(dq, 5);
        std::cout << "Found 5: *it = " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

// vector -> Un tableau dynamique. On peut accéder à n'importe quel élément directement avec v[i], et il s'agrandit automatiquement quand on ajoute des éléments.
// list -> Une liste doublement chaînée. On peut facilement ajouter ou supprimer des éléments n'importe où, mais on ne peut pas accéder directement à l[i]

// stack -> Une pile, dernier entré, premier sorti (LIFO). On ne peut toucher qu'au sommet : push, pop, top. Pas d'itération possible — c'est justement le problème qu'on résout dans l'ex02.

// map -> Une collection de paires clé-valeur, automatiquement triée par clé. Chaque clé est unique.

// deque -> "double-ended queue", une file à deux bouts. C'est comme un vector, mais on peut ajouter ou supprimer des éléments des deux côtés rapidement.