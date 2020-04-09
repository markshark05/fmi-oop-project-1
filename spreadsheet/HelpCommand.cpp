#include "HelpCommand.h"

HelpCommand::HelpCommand(ICommands* loop) :
    Command("help", 0, "prints this information"),
    _loop(loop)
{
}

const std::string HelpCommand::execute()
{
    std::string result;
    std::vector<Command*> commands = _loop->getCommands();
    for (Command*& c : commands)
    {
        result += c->getName();
        result += '\t';
        result += c->getHelpMessage();
        result += '\n';
    }
    return result;
}
