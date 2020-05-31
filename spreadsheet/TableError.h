#pragma once
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
    bool isFileError();
    int getRow();
    int getCol();
};

