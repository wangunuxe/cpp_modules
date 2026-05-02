/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:58:58 by jili              #+#    #+#             */
/*   Updated: 2026/05/02 17:58:59 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
