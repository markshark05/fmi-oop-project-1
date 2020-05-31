#pragma once
#include <string>
#include <stack>
#include <queue>
#include <vector>

#include "Token.h"

/**
 * @brief Represents a mathematical expression parser\n 
 * Implementation of the https://en.wikipedia.org/wiki/Shunting-yard_algorithm\n 
 * Converts the infix representation of the expression to postfix (RPN) and evaluates it
 */
class ExpressionParser
{
public:
    /**
     * @brief Takes a list of tokens and performs the necessary mathematical operations to evaluate their meaning
     * 
     * @param str the tokens list
     * @return Token the single token that repsents the calucaklated value
     */
    Token evaluate(const std::vector<Token>& str) const;
private:
    static std::queue<Token> toRPN(const std::vector<Token>& tokens);
    static Token evaluateRPN(std::queue<Token> queue);
    static int precedence(const Token::Type operatorType);
    static bool left_associative(const Token::Type operatorType);
    static double performOperation(double a, double b, const Token::Type operatorType);
};
