#include <iostream>

#include "CommandLoop.h"
#include "Command.h"
#include "OpenCommand.h"
#include "CloseCommand.h"
#include "SaveCommand.h"
#include "SaveAsCommand.h"
#include "HelpCommand.h"
#include "ExitCommand.h"

int main(int argc, char* argv[])
{
    CommandLoop* loop = new CommandLoop;

    std::vector<Command*> commands{
        new OpenCommand,
        new CloseCommand,
        new SaveCommand,
        new SaveAsCommand,
        new HelpCommand(loop),
        new ExitCommand(loop),
    };

    for (Command*& c : commands)
    {
        loop->addCommand(c);
    }

    loop->Start();

    for (auto& i : commands)
    {
        delete i;
    }
}
