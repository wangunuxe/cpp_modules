#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "用法: ./convert <字面量>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(std::string(argv[1]));
    return 0;
}
