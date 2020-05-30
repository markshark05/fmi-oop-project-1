#pragma once
#include <vector>
#include "Token.h"
class Cell
{
private:
    std::vector<Token> tokens;
public:
    Cell();
    Cell(const std::vector<Token>& tokens);
    std::vector<Token> getTokens() const;
};

