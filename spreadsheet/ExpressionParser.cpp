#include "ExpressionParser.h"

double ExpressionParser::evaluate(const std::vector<Token>& tokens) const
{
    std::queue<Token> rpnQueue{ toRPN(tokens) };
    double result{ evaluateRPN(rpnQueue) };

    return result;
}

// Shunting-yard algorithm
std::queue<Token> ExpressionParser::toRPN(const std::vector<Token>& tokens)
{
    std::stack<Token> operators;
    std::queue<Token> output;

    for (Token const& token : tokens)
    {
        switch (token.getType())
        {
        case Token::Type::String:
        {
            output.push({ "0", Token::Type::Number_i });
        }
        break;
        case Token::Type::Number_i:
        case Token::Type::Number_f:
        {
            output.push(token);
        }
        break;
        case Token::Type::Operator_Plus:
        case Token::Type::Operator_Minus:
        case Token::Type::Operator_Multiply:
        case Token::Type::Operator_Divide:
        case Token::Type::Operator_Pow:
        {
            while (!operators.empty() && (
                left_associative(token.getType()) && precedence(operators.top().getType()) >= precedence(token.getType()) ||
                !left_associative(token.getType()) && precedence(operators.top().getType()) > precedence(token.getType())
                ))
            {
                output.push(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
        break;
        }
    }

    while (!operators.empty())
    {
        output.push(operators.top());
        operators.pop();
    }

    return output;
}

double ExpressionParser::evaluateRPN(std::queue<Token> queue)
{
    std::stack<double> output;

    while (!queue.empty())
    {
        const Token& token{ queue.front() };
        switch (token.getType())
        {
        case Token::Type::Number_i:
        case Token::Type::Number_f:
        {
            double value = std::stod(token.getValue());

            output.push(value);
        }
        break;
        case Token::Type::Operator_Plus:
        case Token::Type::Operator_Minus:
        case Token::Type::Operator_Multiply:
        case Token::Type::Operator_Divide:
        case Token::Type::Operator_Pow:
        {
            double b{ output.top() };
            output.pop();

            double a{ output.top() };
            output.pop();

            double result{ performOperation(a, b, token.getType()) };

            output.push(result);
        }
        break;
        }
        queue.pop();
    }

    if (output.empty())
    {
        return 0;
    }

    return output.top();
}

int ExpressionParser::precedence(const Token::Type operatorType)
{
    switch (operatorType)
    {
    case Token::Type::Operator_Plus:
    case Token::Type::Operator_Minus:
        return 1;
    case Token::Type::Operator_Multiply:
    case Token::Type::Operator_Divide:
        return 2;
    case Token::Type::Operator_Pow:
        return 3;
    }
    return 0;
}

bool ExpressionParser::left_associative(const Token::Type operatorType)
{
    switch (operatorType)
    {
    case Token::Type::Operator_Pow:
        return false;
    default:
        return true;
    }
}

double ExpressionParser::performOperation(double a, double b, const Token::Type operatorType)
{
    switch (operatorType)
    {
    case Token::Type::Operator_Plus:
        return a + b;
    case Token::Type::Operator_Minus:
        return a - b;
    case Token::Type::Operator_Multiply:
        return a * b;
    case Token::Type::Operator_Divide:
        return a / b;
    case Token::Type::Operator_Pow:
        return pow(a, b);
    }
    return 0;
}
