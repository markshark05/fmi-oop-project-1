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
    TableError();
    TableError(bool);
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

