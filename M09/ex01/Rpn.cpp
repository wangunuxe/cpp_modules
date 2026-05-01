#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) { (void)other; }
RPN &RPN::operator=(const RPN &other) { (void)other; return *this; }
RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOperator(char op, int lhs, int rhs) const
{
    switch (op)
    {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '*': return lhs * rhs;
        case '/':
            if (rhs == 0)
                throw std::runtime_error("division by zero");
            return lhs / rhs;
    }
    throw std::runtime_error("unknown operator");
}

// Evaluate using a std::stack<int>
// Tokens are single digits (< 10) or operators +, -, *, /
int RPN::evaluate(const std::string &expression) const
{
    std::stack<int> operands;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isOperator(token))
        {
            // Need at least two operands on the stack
            if (operands.size() < 2)
                throw std::runtime_error("invalid expression");

            int rhs = operands.top(); operands.pop();
            int lhs = operands.top(); operands.pop();
            operands.push(applyOperator(token[0], lhs, rhs));
        }
        else
        {
            // Must be a single digit (0-9)
            if (token.size() != 1 || token[0] < '0' || token[0] > '9')
                throw std::runtime_error("invalid token: " + token);
            operands.push(token[0] - '0');
        }
    }

    if (operands.size() != 1)
        throw std::runtime_error("invalid expression");

    return operands.top();
}