#pragma once
#include <vector>
#include <string>
#include "Token.h"

/**
 * @brief Represents object that can tokenize an input string into instances of Token
 * 
 */
class Tokenizer
{
private:
    enum class State
    {
        Intial,
        String,
        String_e,
        Number_i,
        Number_f,
        Identifier_r,
        Identifier_r_n,
        Identifier_c,
        Identifier_c_n,
    };
    std::vector<Token> tokens;
    std::string str;
    State s;
public:
    /**
     * @brief Construct a new Tokenizer with the input string
     * 
     * @param str the input string
     */
    Tokenizer(const std::string& str);
    /**
     * @brief get the produced tokens by tokenize()
     * 
     * @return std::vector<Token> 
     */
    std::vector<Token> getTokens() const;
    /**
     * @brief attempts to construct a std::vecor of tokens from the provided string
     * 
     * @return true if successful
     * @return false otheriwse
     */
    bool tokenize();
    /**
     * @brief helper method to convert a token to it's escaped string representation
     * 
     * @param token token to stringify
     * @return std::string 
     */
    static std::string stringify(const Token& token);
};
