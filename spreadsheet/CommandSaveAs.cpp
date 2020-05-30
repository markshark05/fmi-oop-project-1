#include "CommandSaveAs.h"

CommandSaveAs::CommandSaveAs(FileContext& fileCtx) :
    Command("saveas", 1, "saveas <file> - saves the currently open file in <file> and switches to it"),
    fileCtx(&fileCtx)
{
}

bool CommandSaveAs::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandSaveAs::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& filename = args[0];

}
