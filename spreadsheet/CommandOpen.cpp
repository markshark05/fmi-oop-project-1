#include "CommandOpen.h"

CommandOpen::CommandOpen() :
    Command("open", 1, "opens <file>")
{
}

void CommandOpen::execute(std::ostream& out, const std::vector<std::string>& args)
{
    out << "open executed" << std::endl;
}
