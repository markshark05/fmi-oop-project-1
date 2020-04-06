#pragma once
#include <string>

class Token
{
public:
    enum class Type {
        Brace,
        Literal,
        Operator,
        Identifier,
    };
    Token(std::string value, Token::Type type);
    Type getType();
    std::string getValue();
private:
    Type _type;
    std::string _value;
};
