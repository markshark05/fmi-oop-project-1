#include "CommandSave.h"

CommandSave::CommandSave(FileContext& fileCtx, Table& table) :
    Command("save", 0, "save - saves the currently open file"),
    fileCtx(&fileCtx),
    table(&table)
{
}

bool CommandSave::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandSave::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    if (table->save(*fileCtx->getActiveFile()))
    {
        out << "File saved successfully" << std::endl;
        return;
    }

    out << "Error: Failed to save file" << std::endl;
}
