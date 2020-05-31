#pragma once
#include <string>

/**
 * @brief Represents a string token with a specific type
 * 
 */
class Token
{
public:
    /**
     * @brief the vailable token types
     * 
     */
    enum class Type
    {
        Empty,
        Operator_Plus,
        Operator_Minus,
        Operator_Multiply,
        Operator_Divide,
        Operator_Pow,
        Operator_Equals,
        Number_i,
        Number_f,
        String,
        Identifier,
    };
private:
    Type _type;
    std::string _value;
public:
    /**
     * @brief Construct a new Token with type Token::Type::Empty
     * 
     */
    Token();
    /**
     * @brief Construct a new Token with char as value and given type
     * 
     * @param c the char to be converted to a string value
     * @param type the type of the Token
     */
    Token(char c, Token::Type type);
    /**
     * @brief Construct a new Token with string as value and given type
     * 
     * @param value the value of the Token
     * @param type the type of the Token
     */
    Token(std::string value, Token::Type type);
    /**
     * @brief Get the Type of the token
     * 
     * @return Type 
     */
    Type getType() const;
    /**
     * @brief Get the stirng value of the token
     * 
     * @return std::string 
     */
    std::string getValue() const;
};
