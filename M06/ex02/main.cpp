#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main(void)
{
    srand(static_cast<unsigned int>(time(NULL)));

    std::cout << "=== 通过指针识别 ===" << std::endl;
    for (int i = 0; i < 6; ++i) {
        Base *obj = generate();
        std::cout << "identify(ptr) -> ";
        identify(obj);
        delete obj;
        std::cout << std::endl;
    }

    std::cout << "=== 通过引用识别 ===" << std::endl;
    for (int i = 0; i < 6; ++i) {
        Base *obj = generate();
        std::cout << "identify(ref) -> ";
        identify(*obj);   // 传引用
        delete obj;
        std::cout << std::endl;
    }

    return 0;
}
