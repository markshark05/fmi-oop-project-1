#include <iostream>
#include <limits>
#include "CommandLoop.h"

CommandLoop::CommandLoop() :
    _running(false)
{
}

CommandLoop::CommandLoop(std::vector<Command*>& commands) :
    _running(false),
    _commands(commands)
{
}

void CommandLoop::Start()
{
    if (!_running)
    {
        _running = true;
        _loop();
    }
}

void CommandLoop::Stop()
{
    _running = false;
}

const std::vector<Command*>& CommandLoop::getCommands() const
{
    return _commands;
}

void CommandLoop::addCommand(Command* command)
{
    _commands.push_back(command);
}

void CommandLoop::_loop()
{
    std::string word;
    while (_running)
    {
        std::cout << "> ";
        std::cin >> word;

        auto iter = std::find_if(_commands.begin(), _commands.end(), [&word](const Command* c)
            {
                return c->getName() == word;
            });

        if (iter == _commands.end())
        {
            std::cout << "command not found" << std::endl;
        }
        else
        {
            Command* command = *iter;
            std::vector<std::string> arguments;
            for (int i = 0; i < command->getParameters(); i++)
            {
                std::cin >> word;
                arguments.push_back(word);
            }
            std::cout << command->execute() << std::endl;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
