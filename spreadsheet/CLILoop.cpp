#include <sstream>
#include "CLILoop.h"

CLILoop::CLILoop(std::istream& in, std::ostream& out, std::vector<Command*>& commands) :
    in(&in),
    out(&out),
    running(false),
    commands(&commands)
{
}

void CLILoop::start()
{
    if (!running)
    {
        running = true;
        loop();
    }
}

void CLILoop::stop()
{
    running = false;
}

const std::vector<Command*>& CLILoop::getCommands() const
{
    return *commands;
}

void CLILoop::loop()
{
    std::istream& in{ *this->in };
    std::ostream& out{ *this->out };

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
            for (Command* const& c : *commands)
            {
                if (c->getName() == commandStr)
                {
                    command = c;
                }
            }

            if (command)
            {
                std::vector<std::string> args = parseArgs(linestream);
                if (!command->fileRequirement())
                {
                    out << "Command requires an open file." << std::endl;
                }
                else if ((int)args.size() < command->getMinArgsCount())
                {
                    out << "Expected " << command->getMinArgsCount() << " argument(s) but got " << args.size() << "." << std::endl;
                }
                else
                {
                    command->execute(in, out, args);
                }
            }
            else
            {
                out << "Unknown command \"" << commandStr << "\"." << std::endl;
            }
        }
    }
}

std::vector<std::string> CLILoop::parseArgs(std::istringstream& linestream)
{
    std::vector<std::string> args;
    std::string token;
    while(linestream >> token)
    {
        args.push_back(token);
    }

    return args;
}
