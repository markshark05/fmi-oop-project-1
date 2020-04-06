#include "Tokenizer.h"

std::vector<Token> Tokenizer::tokenize(std::string str)
{
    std::vector<Token> tokens;

    while (!str.empty()) {
        const char c = str.front();
        if (c >= '0' && c <= '9') {
            size_t idx;
            double num = std::stod(str, &idx);
            Token token(std::to_string(num), Token::Type::Literal);
            tokens.push_back(token);
            str.erase(0, idx);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            Token token(std::to_string(c), Token::Type::Operator);
            str.erase(0, 1);
        }
        else if (c == '(' || c == ')') {
            Token token(std::to_string(c), Token::Type::Brace);
            str.erase(0, 1);
        }
    }

    return tokens;
}
