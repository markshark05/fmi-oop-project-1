#include "Token.h"

Token::Token() :
    _type(Type::Empty)
{
}

Token::Token(char c, Token::Type type) :
    Token(std::string(1, c), type)
{
}

Token::Token(std::string value, Token::Type type) :
    _value(value),
    _type(type)
{
}

Token::Type Token::getType() const
{
    return _type;
}

std::string Token::getValue() const
{
    return _value;
}
