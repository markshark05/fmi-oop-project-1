#include <sstream>
#include "CommandLoop.h"

#include "CommandOpen.h"
#include "CommandClose.h"
#include "CommandSave.h"
#include "CommandSaveAs.h"

#include "CommandEdit.h"
#include "CommandPrint.h"

#include "CommandHelp.h"
#include "CommandExit.h"


CommandLoop::CommandLoop(std::istream& in, std::ostream& out) :
    in(in),
    out(out),
    running(false),
    commands{
        new CommandOpen,
        new CommandClose,
        new CommandSave,
        new CommandSaveAs,

        new CommandEdit,
        new CommandPrint,

        new CommandHelp{ this },
        new CommandExit{ this }, 
}
{
}

void CommandLoop::Start()
{
    if (!running)
    {
        running = true;
        loop();
    }
}

void CommandLoop::Stop()
{
    running = false;
}

const std::vector<Command*>& CommandLoop::getCommands() const
{
    return commands;
}

void CommandLoop::loop()
{
    while (running)
    {
        out << "> ";
        std::string line;
        std::getline(in, line);

        std::istringstream linestream{ line };
        std::string commandStr;
        if (linestream >> commandStr)
        {
            Command* command = nullptr;
            for (Command* const& c : commands)
            {
                if (c->getName() == commandStr)
                {
                    command = c;
                }
            }

            if (command)
            {
                std::vector<std::string> args = parseArgs(linestream, command->getMinArgsCount());
                if (args.size() != command->getMinArgsCount())
                {
                    out << "Expected " << command->getMinArgsCount() << " argument(s) but got " << args.size() << "." << std::endl;
                }
                else
                {
                    command->execute(out, args);
                }
            }
            else
            {
                out << "Unknown command \"" << commandStr << "\"." << std::endl;
            }
        }
    }
}

std::vector<std::string> CommandLoop::parseArgs(std::istringstream& linestream, unsigned int max)
{
    std::vector<std::string> args;
    std::string token;
    for (unsigned int i = 0; i < max && linestream >> token; i++)
    {
        args.push_back(token);
    }
    return args;
}
