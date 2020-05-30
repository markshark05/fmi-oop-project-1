#include <iomanip>
#include "CommandPrint.h"

CommandPrint::CommandPrint(const FileContext& fileCtx, const Table& table) :
    Command("print", 0, "print - prints the current table"),
    fileCtx(&fileCtx),
    table(&table)
{
}

bool CommandPrint::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandPrint::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    int rows = table->getRows();
    int cols = table->getCols();

    std::vector<unsigned> col_widths(cols);
    
    std::vector<std::vector<std::string>> buffer;
    buffer.reserve(rows);
    
    for (int i = 0; i < rows; i++)
    {
        std::vector<std::string> row;
        row.reserve(cols);
        for (int j = 0; j < cols; j++)
        {
            std::string value = table->getCellValue(i, j);
            col_widths[j] = std::max(col_widths[j], value.size() + 1);
            row.push_back(value);
        }
        buffer.push_back(row);
    }

    out << std::left;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j != 0)
            {
                out << "| ";
            }
            out << std::setw(col_widths[j]) << buffer[i][j];
        }
        out << std::endl;
    }
}
