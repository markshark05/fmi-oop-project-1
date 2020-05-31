#include "CommandEdit.h"
#include "CellIdentifier.h"

CommandEdit::CommandEdit(const FileContext& fileCtx, Table& table) :
    Command("edit", 1, "edit <RnCn> - prompts for the new value of the cell"),
    fileCtx(&fileCtx),
    table(&table)
{
}

bool CommandEdit::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandEdit::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& cellidStr = args[0];

    CellIdentifier cellid;
    if (!CellIdentifier::tryParse(cellidStr, cellid))
    {
        out << "Error: Invalid cell id" << std::endl;
        return;
    }

    std::string newCellValue = promptLine(in, out, "Value");
    if (!table->setCellValue(cellid.getRow(), cellid.getCol(), newCellValue))
    {
        out << "Error: Invalid token in new cell value" << std::endl;
        return;
    }

    out << "Cell updated sucessfully" << std::endl;
}
