#include "Command.h"

Command::Command(const std::string& name, int parameters, const std::string& helpMessage) :
    _name(name),
    _parameters(parameters),
    _helpMessage(helpMessage)
{
}

const std::string& Command::getName() const
{
    return _name;
}

int Command::getParameters() const
{
    return _parameters;
}

const std::string& Command::getHelpMessage() const
{
    return _helpMessage;
}
