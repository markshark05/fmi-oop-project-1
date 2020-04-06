#include "ExpressionParser.h"

#include <stack>

double ExpressionParser::evaluate(const std::string& str) {
    std::stack<double> operands;
    std::stack<char> operators;

    for (unsigned int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isDigit(c)) {
            int num = 0;
            while (isDigit(c)) {
                num = num * 10 + (c - '0');
                i++;
                if (i < str.length())
                    c = str[i];
                else
                    break;
            }
            i--;
            operands.push(num);
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (operators.top() != '(') {
                double output = performOperation(operands, operators);
                operands.push(output);
            }
            operators.pop();
        }
        else if (isOperator(c)) {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                double output = performOperation(operands, operators);
                operands.push(output);
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        double output = performOperation(operands, operators);
        operands.push(output);
    }
    return operands.top();
}

bool ExpressionParser::isDigit(const char ch) {
    return ch >= '0' && ch <= '9';
}

int ExpressionParser::precedence(const char c) {
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

double ExpressionParser::performOperation(std::stack<double>& numbers, std::stack<char>& operations) {
    double a = numbers.top();
    numbers.pop();
    
    double b = numbers.top();
    numbers.pop();
    
    char operation = operations.top(); 
    operations.pop();
    
    switch (operation) {
    case '+':
        return a + b;
    case '-':
        return b - a;
    case '*':
        return a * b;
    case '/':
        return b / a;
    }
    return 0;
}

bool ExpressionParser::isOperator(const char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*' || c == '^');
}