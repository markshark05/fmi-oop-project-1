#include "CommandOpen.h"

CommandOpen::CommandOpen(FileContext& fileCtx) :
    Command("open", 1, "open <file> - loads <file> creating new one if does not exist"),
    fileCtx(&fileCtx)
{
}

void CommandOpen::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    const std::string& filename = args[0];
}
