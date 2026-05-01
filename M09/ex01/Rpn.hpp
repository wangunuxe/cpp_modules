#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    // Evaluate an RPN expression string; throws on error
    int evaluate(const std::string &expression) const;

private:
    bool isOperator(const std::string &token) const;
    int  applyOperator(char op, int lhs, int rhs) const;
};

#endif