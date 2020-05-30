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
    };
public:
    std::vector<Token> tokenize(const std::string& str) const;
private:
    void token_outside(State& s, std::vector<Token>& tokens, std::string& curr_str, const char c) const;
};
