#include "ExpressionParser.h"

Token ExpressionParser::evaluate(const std::vector<Token>& tokens) const
{
    std::queue<Token> rpnQueue{ toRPN(tokens) };
    Token result{ evaluateRPN(rpnQueue) };

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
        case Token::Type::Empty:
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

Token ExpressionParser::evaluateRPN(std::queue<Token> queue)
{
    std::stack<Token> output;

    while (!queue.empty())
    {
        const Token& token{ queue.front() };
        switch (token.getType())
        {
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
            Token b{ output.top() };
            output.pop();

            Token a{ output.top() };
            output.pop();

            double aval = std::stod(a.getValue());
            double bval = std::stod(b.getValue());
            double resultval = performOperation(aval, bval, token.getType());

            Token result;
            if (a.getType() == Token::Type::Number_i && b.getType() == Token::Type::Number_i)
            {
                result = Token{ std::to_string(static_cast<int>(resultval)), Token::Type::Number_i };
            }
            else
            {
                result = Token{ std::to_string(resultval), Token::Type::Number_f };
            }

            output.push(result);
        }
        break;
        }
        queue.pop();
    }

    if (output.empty())
    {
        return Token{};
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
