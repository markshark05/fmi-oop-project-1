#include "OpenCommand.h"

OpenCommand::OpenCommand() :
    Command("open", 1, "opens <file>")
{
}

const std::string OpenCommand::execute()
{
    return "open executed";
}
