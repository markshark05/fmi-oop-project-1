#pragma once
#include <string>
#include <stack>
#include <queue>
#include <vector>

#include "Token.h"

class ExpressionParser
{
public:
    Token evaluate(const std::vector<Token>& str) const;
private:
    static std::queue<Token> toRPN(const std::vector<Token>& tokens);
    static Token evaluateRPN(std::queue<Token> queue);
    static int precedence(const Token::Type operatorType);
    static bool left_associative(const Token::Type operatorType);
    static double performOperation(double a, double b, const Token::Type operatorType);
};
