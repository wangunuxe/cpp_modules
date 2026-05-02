/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:59:31 by jili              #+#    #+#             */
/*   Updated: 2026/05/02 17:59:32 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
    // 创建 Data 对象
    Data original;
    original.id    = 42;
    original.name  = "test_data";
    original.value = 3.14;

    std::cout << "=== 序列化测试 ===" << std::endl;
    std::cout << "原始指针地址  : " << &original << std::endl;
    std::cout << "原始数据 id   : " << original.id << std::endl;
    std::cout << "原始数据 name : " << original.name << std::endl;
    std::cout << "原始数据 value: " << original.value << std::endl;

    // 序列化：指针 → 整数
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "\n序列化后整数值: " << raw << std::endl;

    // 反序列化：整数 → 指针
    Data *restored = Serializer::deserialize(raw);
    std::cout << "反序列化指针  : " << restored << std::endl;

    // 验证
    std::cout << "\n=== 验证 ===" << std::endl;
    if (restored == &original)
        std::cout << "✓ 指针相等，序列化/反序列化成功！" << std::endl;
    else
        std::cout << "✗ 指针不相等，测试失败！" << std::endl;

    std::cout << "恢复数据 id   : " << restored->id << std::endl;
    std::cout << "恢复数据 name : " << restored->name << std::endl;
    std::cout << "恢复数据 value: " << restored->value << std::endl;

    return 0;
}
