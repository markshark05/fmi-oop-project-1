#pragma once

/**
 * @brief Represents an error encountered during the loading of a table file
 * 
 */
class TableError
{
private:
    bool fileError;
    int row;
    int col;
public:
    /**
     * @brief Construct a new TableError with no errors
     * 
     */
    TableError();
    /**
     * @brief Construct a new TableError with file open error
     * 
     */
    TableError(bool);
    /**
     * @brief Construct a new TableError with invalid data in cell error
     * 
     * @param row 
     * @param col 
     */
    TableError(unsigned row, unsigned col);
    /**
     * 
     * @return true if the type of error is a file open error
     * @return false otheriwse
     */
    bool isFileError();
    /**
     * @brief the row at wihcih an error was encountered otherwise -1
     * 
     * @return int 
     */
    int getRow();
    /**
     * @brief the column at wihcih an error was encountered otherwise -1
     * 
     * @return int 
     */
    int getCol();
};

