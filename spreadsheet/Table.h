#pragma once
#include <string>
#include <map>

#include "Cell.h"
#include "CSVReader.h"
#include "CSVWriter.h"
#include "Tokenizer.h"
#include "ExpressionParser.h"
#include "TableError.h"

/**
 * @brief Contains the current in-memory representation of the spreasheet
 * 
 */
class Table
{
private:
    const CSVReader* reader;
    const CSVWriter* writer;
    const ExpressionParser* parser;

    std::map<std::pair<unsigned, unsigned>, Cell> table;

    unsigned rows;
    unsigned cols;
public:
    /**
     * @brief Construct a new Table instance with given reader, writer and parser
     * 
     * @param reader 
     * @param writer 
     * @param parser 
     */
    Table(const CSVReader& reader, const CSVWriter& writer, const ExpressionParser& parser);
    /**
     * @brief Get the total number of rows 
     * 
     * @return unsigned 
     */
    unsigned getRows() const;
    /**
     * @brief Get the total number of columns
     * 
     * @return unsigned 
     */
    unsigned getCols() const;

    /**
     * @brief Get the evaluated value of the cell at (row, col) as a string
     * 
     * @param row row number
     * @param col column number
     * @return std::string
     */
    std::string getCellString(unsigned row, unsigned col) const;
    /**
     * @brief Get the evaluated value of the cell at (row, col) as a token
     * 
     * @param row row number
     * @param col column number
     * @return Token Token::Type::Empty if the value is outisde getRows() or getCols() 
     */
    Token getCellValue(unsigned row, unsigned col) const;
    /**
     * @brief Attempts to parse and set a new value for the given cell
     * 
     * @param row row number
     * @param col colum number
     * @param cellStr the new raw cell value
     * @return true if the value was accepted and set
     * @return false otheriwse
     */
    bool setCellValue(unsigned row, unsigned col, const std::string& cellStr);

    /**
     * @brief replaces the current in-memory table with the one represented in fileName
     * 
     * @param fileName the file name of the table
     * @param error the errors encountered during loading
     * @return true if the load was sucessful
     * @return false otherwise
     */
    bool load(const std::string& fileName, TableError& error);
    /**
     * @brief writes the current in-memory table to file overwriting it
     * 
     * @param fileName 
     * @return true 
     * @return false 
     */
    bool save(const std::string& fileName) const;
};
