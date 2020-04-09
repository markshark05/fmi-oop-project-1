#include "CloseCommand.h"

CloseCommand::CloseCommand() :
    Command("close", 0, "closes currently opened file")
{
}

const std::string CloseCommand::execute()
{
    return "close executed";
}
