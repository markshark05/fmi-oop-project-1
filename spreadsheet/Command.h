#pragma once
#include <ostream>
#include <string>
#include <vector>

class Command
{
public:
    Command(const std::string& name, int minArgsCount, const std::string& helpMessage);
    const std::string& getName() const;
    int getMinArgsCount() const;
    const std::string& getHelpMessage() const;
    virtual void execute(std::ostream& out, const std::vector<std::string>& args) = 0;
private:
    std::string name;
    int minArgsCount;
    std::string helpMessage;
};
