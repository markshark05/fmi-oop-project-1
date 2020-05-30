#pragma once
#include <string>

class CellIdentifier
{
private:
    const unsigned OFFSET{ 1 };
    unsigned row;
    unsigned col;
public:
    CellIdentifier(const std::string& str);
    CellIdentifier(unsigned row, unsigned col);
    unsigned getRow() const;
    unsigned getCol() const;
    std::string toString() const;
};
