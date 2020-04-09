#include "SaveCommand.h"

SaveCommand::SaveCommand()
    : Command("save", 0, "saves the currently open file")
{
}

const std::string SaveCommand::execute()
{
    return "save executed";
}
