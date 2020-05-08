#include "CommandPrint.h"

CommandPrint::CommandPrint() :
    Command("print", 0, "prints the current table")
{
}

void CommandPrint::execute(std::ostream& out, const std::vector<std::string>& args)
{
    out << "print executed" << std::endl;
}
