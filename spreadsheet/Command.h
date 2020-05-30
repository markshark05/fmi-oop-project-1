#pragma once
#include <iostream>
#include <string>
#include <vector>

class Command
{
private:
    std::string name;
    int minArgsCount;
    std::string helpMessage;
public:
    Command(const std::string& name, int minArgsCount, const std::string& helpMessage);
    
    const std::string& getName() const;
    int getMinArgsCount() const;
    const std::string& getHelpMessage() const;

    virtual bool fileRequirement();
    virtual void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) = 0;
protected:
    std::string promptLine(std::istream& in, std::ostream& out, const std::string& prompt);
};
