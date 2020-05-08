#include "CommandSaveAs.h"

CommandSaveAs::CommandSaveAs() :
    Command("saveas", 1, "saves the currently open file in <file>")
{
}

void CommandSaveAs::execute(std::ostream& out, const std::vector<std::string>& args)
{
    out << "saveas executed" << std::endl;
}
