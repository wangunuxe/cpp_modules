#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>   // uintptr_t（C++98 兼容）
# include "Data.hpp"

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &src);
    Serializer &operator=(const Serializer &rhs);
    ~Serializer();

public:
    // 将指针转换为无符号整数（使用 reinterpret_cast）
    static uintptr_t serialize(Data *ptr);

    // 将无符号整数还原为指针（使用 reinterpret_cast）
    static Data *deserialize(uintptr_t raw);
};

#endif
