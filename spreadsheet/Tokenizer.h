#pragma once
#include <vector>
#include <string>
#include "Token.h"

class Tokenizer
{
public:
    enum class State {
        Intial,
        String,
        String_e,
        Number_i,
        Number_f
    };
    static std::vector<Token> tokenize(std::string str);
private:
    static void token_begin(State& s, std::vector<Token>& tokens, std::string& curr_str, const char c);
};
