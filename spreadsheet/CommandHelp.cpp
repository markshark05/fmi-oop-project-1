#include "CommandHelp.h"

CommandHelp::CommandHelp(ICommands* loop) :
    Command("help", 0, "prints this information"),
    _loop(loop)
{
}

void CommandHelp::execute(std::ostream& out, const std::vector<std::string>& args)
{
    std::vector<Command*> commands = _loop->getCommands();
    for (Command*& c : commands)
    {
        out << c->getName() << '\t';
        out << c->getHelpMessage() << std::endl;
    }
}
