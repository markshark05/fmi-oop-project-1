#include "CommandEdit.h"

CommandEdit::CommandEdit()
    :Command("edit", 1, "edit <Rx:Cx> - prompts for the new value of the cell")
{
}

bool CommandEdit::fileRequirement()
{
    return false;
}

void CommandEdit::execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args)
{
    out << "edit executed" << std::endl;
}
