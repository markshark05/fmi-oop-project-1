#include "CommandSave.h"

CommandSave::CommandSave(FileContext& fileCtx) :
    Command("save", 0, "save - saves the currently open file"),
    fileCtx(&fileCtx)
{
}

bool CommandSave::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandSave::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
}
