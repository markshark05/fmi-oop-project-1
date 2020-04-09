#pragma once
#include <string>

class Command
{
public:
    Command(const std::string& name, int parameters, const std::string& helpMessage);
    const std::string& getName() const;
    int getParameters() const;
    const std::string& getHelpMessage() const;
    virtual const std::string execute() = 0;
private:
    std::string _name;
    int _parameters;
    std::string _helpMessage;
};
