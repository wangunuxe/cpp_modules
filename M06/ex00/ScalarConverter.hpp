/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:59:10 by jili              #+#    #+#             */
/*   Updated: 2026/05/02 17:59:11 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <limits>
# include <cmath>
# include <cerrno>
# include <climits>

class ScalarConverter
{
private:
    ScalarConverter();                                  // 不可实例化
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &rhs);
    ~ScalarConverter();

    // 类型检测辅助
    static bool isChar(const std::string &s);
    static bool isInt(const std::string &s);
    static bool isFloat(const std::string &s);
    static bool isDouble(const std::string &s);
    static bool isPseudoLiteral(const std::string &s);

    // 各类型转换输出
    static void convertFromChar(const std::string &s);
    static void convertFromInt(const std::string &s);
    static void convertFromFloat(const std::string &s);
    static void convertFromDouble(const std::string &s);
    static void handlePseudoLiteral(const std::string &s);

    // 显示辅助
    static void printChar(double val);
    static void printInt(double val);
    static void printFloat(double val);
    static void printDouble(double val);

public:
    static void convert(const std::string &s);
};

#endif
