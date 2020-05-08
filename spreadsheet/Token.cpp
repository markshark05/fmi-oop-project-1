#include "Token.h"

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
