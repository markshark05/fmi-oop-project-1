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
    for (unsigned i = 0; i < table->getRows(); i++)
    {
        for (unsigned j = 0; j < table->getCols(); j++)
        {
            out << table->getCellValue(i, j) << " | ";
        }
        out << std::endl;
    }
}
