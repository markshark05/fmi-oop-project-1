#include "TableError.h"

TableError::TableError() :
    fileError(false),
    row(-1),
    col(-1)
{
}

TableError::TableError(bool fileError) : TableError()
{
    this->fileError = fileError;
}

TableError::TableError(unsigned row, unsigned col) : TableError()
{
    this->row = row + 1;
    this->col = col + 1;
}

bool TableError::isFileError()
{
    return fileError;
}

int TableError::getRow()
{
    return row;
}

int TableError::getCol()
{
    return col;
}