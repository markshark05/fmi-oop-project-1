#include "CommandPrint.h"

CommandPrint::CommandPrint() :
    Command("print", 0, "print - prints the current table")
{
}

void CommandPrint::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    out << "print executed" << std::endl;
}
