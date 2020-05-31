#include <sstream>
#include "CellIdentifier.h"
#include "Tokenizer.h"

CellIdentifier::CellIdentifier() :
    CellIdentifier(0, 0)
{
}

CellIdentifier::CellIdentifier(unsigned row, unsigned col) :
    row(row),
    col(col)
{
}

unsigned CellIdentifier::getRow() const
{
    return row;
}

unsigned CellIdentifier::getCol() const
{
    return col;
}

std::string CellIdentifier::toString() const
{
    std::stringstream fmt;
    fmt << 'R' << (row + OFFSET) << 'C' << (col + OFFSET);
    return fmt.str();
}

bool CellIdentifier::tryParse(const std::string& str, CellIdentifier& identifier)
{
    Tokenizer tokenizer{ str };
    if (!tokenizer.tokenize())
    {
        return false;
    }

    std::vector<Token> tokens = tokenizer.getTokens();
    if (tokens.size() != 1 || tokens[0].getType() != Token::Type::Identifier)
    {
        return false;
    }

    size_t c_pos = str.find("C");
    int rowVal = std::stoi(str.substr(1, c_pos - 1));
    int colVal = std::stoi(str.substr(c_pos + 1));

    if (rowVal < 1 || colVal < 1)
    {
        return false;
    }

    identifier.row = rowVal - OFFSET;
    identifier.col = colVal - OFFSET;
    return true;
}
