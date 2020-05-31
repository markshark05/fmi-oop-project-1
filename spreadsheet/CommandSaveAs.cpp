#include "CommandSaveAs.h"

CommandSaveAs::CommandSaveAs(FileContext& fileCtx, Table& table) :
    Command("saveas", 1, "saveas <file> - saves the currently open file in <file> and switches to it"),
    fileCtx(&fileCtx),
    table(&table)
{
}

bool CommandSaveAs::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandSaveAs::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& filename = args[0];

    if (table->save(filename))
    {
        fileCtx->setActiveFile(filename);
        out << "File saved successfully. Open file switeched to" << filename << std::endl;
        return;
    }

    out << "Error: Failed to save file" << std::endl;
}
