/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:59:45 by jili              #+#    #+#             */
/*   Updated: 2026/05/02 17:59:46 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

/* ─── Base 析构函数 ─── */
Base::~Base() {}

/* ─── generate：随机实例化 A、B 或 C ─── */
Base *generate(void)
{
    // 用 rand() 产生 0/1/2，对应三个派生类
    int choice = rand() % 3;
    if (choice == 0) {
        std::cout << "[generate] 创建了 A" << std::endl;
        return new A();
    } else if (choice == 1) {
        std::cout << "[generate] 创建了 B" << std::endl;
        return new B();
    } else {
        std::cout << "[generate] 创建了 C" << std::endl;
        return new C();
    }
}

/* ─── identify(Base* p)：通过指针识别
       使用 dynamic_cast<T*>，失败时返回 NULL ─── */
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "未知类型" << std::endl;
}

/* ─── identify(Base& p)：通过引用识别
       使用 dynamic_cast<T&>，失败时抛出 std::bad_cast
       ★ 此函数内部禁止使用指针 ─── */
void identify(Base &p)
{
    // dynamic_cast 对引用失败时抛出异常，用 try/catch 捕获
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "未知类型" << std::endl;
}
