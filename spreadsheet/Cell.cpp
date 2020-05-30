#include "Cell.h"

Cell::Cell()
{
}

Cell::Cell(const std::vector<Token>& tokens) :
    tokens(tokens)
{
}

std::vector<Token>& Cell::getTokens()
{
    return tokens;
}
