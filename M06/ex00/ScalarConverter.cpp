#include "ScalarConverter.hpp"

/* ─── 构造（私有，不实现） ─── */
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

/* ─── 类型检测 ─── */

bool ScalarConverter::isChar(const std::string &s)
{
    // 形如 'a'
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

bool ScalarConverter::isInt(const std::string &s)
{
    if (s.empty()) return false;
    size_t i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    if (i == s.length()) return false;
    for (; i < s.length(); ++i)
        if (!std::isdigit(s[i])) return false;
    return true;
}

bool ScalarConverter::isFloat(const std::string &s)
{
    if (s.empty() || s[s.length() - 1] != 'f') return false;
    std::string without_f = s.substr(0, s.length() - 1);
    bool has_dot = false;
    size_t i = (without_f[0] == '-' || without_f[0] == '+') ? 1 : 0;
    if (i == without_f.length()) return false;
    for (; i < without_f.length(); ++i) {
        if (without_f[i] == '.') {
            if (has_dot) return false;
            has_dot = true;
        } else if (!std::isdigit(without_f[i])) {
            return false;
        }
    }
    return has_dot;
}

bool ScalarConverter::isDouble(const std::string &s)
{
    if (s.empty()) return false;
    bool has_dot = false;
    size_t i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    if (i == s.length()) return false;
    for (; i < s.length(); ++i) {
        if (s[i] == '.') {
            if (has_dot) return false;
            has_dot = true;
        } else if (!std::isdigit(s[i])) {
            return false;
        }
    }
    return has_dot;
}

bool ScalarConverter::isPseudoLiteral(const std::string &s)
{
    return (s == "-inff" || s == "+inff" || s == "nanf"
         || s == "-inf"  || s == "+inf"  || s == "nan");
}

/* ─── 显示辅助（使用 static_cast 进行显式转换） ─── */

void ScalarConverter::printChar(double val)
{
    if (std::isnan(val) || std::isinf(val)
        || val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(val)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

void ScalarConverter::printInt(double val)
{
    if (std::isnan(val) || std::isinf(val)
        || val > static_cast<double>(INT_MAX)
        || val < static_cast<double>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

void ScalarConverter::printFloat(double val)
{
    float f = static_cast<float>(val);
    std::cout << "float: ";
    if (std::isinf(f))
        std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
    else if (std::isnan(f))
        std::cout << "nanf" << std::endl;
    else {
        // 若没有小数部分，强制显示 .0
        if (f == static_cast<float>(static_cast<long long>(f)))
            std::cout << f << ".0f" << std::endl;
        else
            std::cout << f << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double val)
{
    std::cout << "double: ";
    if (std::isinf(val))
        std::cout << (val > 0 ? "+inf" : "-inf") << std::endl;
    else if (std::isnan(val))
        std::cout << "nan" << std::endl;
    else {
        if (val == static_cast<double>(static_cast<long long>(val)))
            std::cout << val << ".0" << std::endl;
        else
            std::cout << val << std::endl;
    }
}

/* ─── 各类型转换入口 ─── */

void ScalarConverter::convertFromChar(const std::string &s)
{
    char c = s[1];
    double val = static_cast<double>(c);
    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}

void ScalarConverter::convertFromInt(const std::string &s)
{
    std::istringstream iss(s);
    long long raw;
    iss >> raw;
    double val = static_cast<double>(raw);
    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}

void ScalarConverter::convertFromFloat(const std::string &s)
{
    std::istringstream iss(s.substr(0, s.length() - 1)); // 去掉 'f'
    float f;
    iss >> f;
    double val = static_cast<double>(f);
    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}

void ScalarConverter::convertFromDouble(const std::string &s)
{
    std::istringstream iss(s);
    double val;
    iss >> val;
    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}

void ScalarConverter::handlePseudoLiteral(const std::string &s)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (s == "-inff" || s == "-inf") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } else if (s == "+inff" || s == "+inf") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else { // nanf / nan
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

/* ─── 主入口 ─── */

void ScalarConverter::convert(const std::string &s)
{
    if (isPseudoLiteral(s))
        handlePseudoLiteral(s);
    else if (isChar(s))
        convertFromChar(s);
    else if (isInt(s))
        convertFromInt(s);
    else if (isFloat(s))
        convertFromFloat(s);
    else if (isDouble(s))
        convertFromDouble(s);
    else
        std::cout << "错误：无法识别的字面量类型" << std::endl;
}
