#pragma once
#include <vector>
#include "Token.h"

class Tokenizer
{
public:
    std::vector<Token> tokenize(std::string str);
};
