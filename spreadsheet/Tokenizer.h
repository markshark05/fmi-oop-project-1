#pragma once
#include <vector>
#include <string>
#include "Token.h"

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
    Tokenizer(const std::string& str);
    std::vector<Token> getTokens() const;
    bool tokenize();
    static std::string stringify(const Token& token);
};
