#pragma once
#include <string>
#include <stack>

class ExpressionParser
{
public:
    static double evaluate(const std::string& str);
private:
    static bool isOperator(const char c);
    static bool isDigit(const char ch);
    static int precedence(const char c);
    static double performOperation(std::stack<double>& numbers, std::stack<char>& operations);
};

