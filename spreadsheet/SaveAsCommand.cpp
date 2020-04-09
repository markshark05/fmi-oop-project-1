#include "SaveAsCommand.h"

SaveAsCommand::SaveAsCommand() :
    Command("saveas", 1, "saves the currently open file in <file>")
{
}

const std::string SaveAsCommand::execute()
{
    return "saveas executed";
}
