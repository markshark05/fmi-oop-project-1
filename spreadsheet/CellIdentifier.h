#pragma once
#include <string>

class CellIdentifier
{
private:
    static const unsigned OFFSET{ 1 };
    unsigned row;
    unsigned col;
public:
    CellIdentifier();
    CellIdentifier(unsigned row, unsigned col);
    unsigned getRow() const;
    unsigned getCol() const;
    
    std::string toString() const;
    static bool tryParse(const std::string& str, CellIdentifier& identifier);
};
