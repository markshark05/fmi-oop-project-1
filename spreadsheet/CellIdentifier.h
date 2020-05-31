#pragma once
#include <string>

/**
 * @brief Represents a cell id in the format R<n>C<n>
 * 
 */
class CellIdentifier
{
private:
    static const unsigned OFFSET{ 1 };
    unsigned row;
    unsigned col;
public:
    /**
     * @brief Construct a new Cell Identifier object with 0,0 coords
     * 
     */
    CellIdentifier();
    /**
     * @brief Construct a new Cell Identifier objectwith given row and col
     * 
     * @param row the zero based row index 
     * @param col the zero based column index
     */
    CellIdentifier(unsigned row, unsigned col);
    /**
     * @brief Get the row value
     * 
     * @return unsigned zero based index
     */
    unsigned getRow() const;
    /**
     * @brief Get the column value
     * 
     * @return unsigned zero based index
     */
    unsigned getCol() const;
    
    /**
     * @brief Returns the string repseentation of the CellId with 1 based indexes
     * 
     * @return std::string 
     */
    std::string toString() const;
    /**
     * @brief Attempts to create an instance from string
     * 
     * @param str the string to be parsed
     * @param identifier the output id
     * @return true if the string is a valid identifier and was set
     * @return false otherwise
     */
    static bool tryParse(const std::string& str, CellIdentifier& identifier);
};
