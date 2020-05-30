#include <sstream>
#include "CellIdentifier.h"

CellIdentifier::CellIdentifier(const std::string& str)
{
    unsigned c_pos = str.find("C");
    row = std::stoi(str.substr(1, c_pos - 1)) - OFFSET;
    col = std::stoi(str.substr(c_pos + 1)) - OFFSET;
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
