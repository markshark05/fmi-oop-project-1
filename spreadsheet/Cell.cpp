#include "Cell.h"

Cell::Cell()
{
}

Cell::Cell(const std::vector<Token>& tokens) :
    tokens(tokens)
{
}

const std::vector<Token>& Cell::getTokens() const
{
    return tokens;
}
