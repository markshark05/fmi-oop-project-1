#pragma once
#include <string>
#include <stack>
#include <queue>
#include <vector>

#include "Token.h"

/**
 * @brief Represents a mathematical expression parser
 * 
 */
class ExpressionParser
{
public:
    /**
     * @brief Takes a list of tokens and performs the necessary mathematical operations to evaluate their meaning
     * 
     * @param str 
     * @return Token the single token that repsents the calucaklated value
     */
    Token evaluate(const std::vector<Token>& str) const;
private:
    /**
     * @brief Implementation of the https://en.wikipedia.org/wiki/Shunting-yard_algorithm
     * Converts the infix representation of the expression to postfix (RPN)
     * @param tokens the input tokens
     * @return std::queue<Token> the rearanged tokens with operators athe the end
     */
    static std::queue<Token> toRPN(const std::vector<Token>& tokens);
    /**
     * @brief takes the postfix notation and evaluates it
     * 
     * @param queue 
     * @return Token 
     */
    static Token evaluateRPN(std::queue<Token> queue);
    static int precedence(const Token::Type operatorType);
    static bool left_associative(const Token::Type operatorType);
    static double performOperation(double a, double b, const Token::Type operatorType);
};
