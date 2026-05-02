/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:59:52 by jili              #+#    #+#             */
/*   Updated: 2026/05/02 17:59:54 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
