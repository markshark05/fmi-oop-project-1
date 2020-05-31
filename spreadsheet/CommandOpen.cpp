#include "CommandOpen.h"

CommandOpen::CommandOpen(FileContext& fileCtx, Table& table) :
    Command("open", 1, "open <file> - loads <file> creating new one if does not exist"),
    fileCtx(&fileCtx),
    table(&table)
{
}

void CommandOpen::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& filename = args[0];

    if (fileCtx->getActiveFile())
    {
        out << "File already open, please close it first." << std::endl;
        return;
    }

    TableError err;
    if (table->load(filename, err))
    {
        fileCtx->setActiveFile(filename);
        out << "File loaded succesfully." << std::endl;
        return;
    }

    if (err.isFileError())
    {
        out << "Error: Failed to open file" << std::endl;
        return;
    }

    out << "Error: Row " << err.getRow() << ", Col " << err.getCol() << " - invalid token" << std::endl;
}
