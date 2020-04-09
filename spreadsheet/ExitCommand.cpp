#include "ExitCommand.h"

ExitCommand::ExitCommand(IStoppable* loop) :
    Command("exit", 0, "exists the program"),
    _loop(loop)
{
}

const std::string ExitCommand::execute()
{
    _loop->Stop();
    return "Exiting the program...";
}
