#include "CommandClose.h"
#include "FileContext.h"

CommandClose::CommandClose(FileContext& fileCtx) :
    Command("close", 0, "close - closes currently opened file"),
    fileCtx(&fileCtx)
{
}

bool CommandClose::fileRequirement()
{
    return fileCtx->getActiveFile();
}

void CommandClose::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    fileCtx->clearActiveFile();
    out << "File closed successfully" << std::endl;
}
