#include "CommandEdit.h"

CommandEdit::CommandEdit()
    :Command("edit", 1, "")
{
}

void CommandEdit::execute(std::ostream& out, const std::vector<std::string>& args)
{
    out << "edit executed" << std::endl;
}
