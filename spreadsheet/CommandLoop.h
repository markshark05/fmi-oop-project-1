#pragma once
#include <vector>
#include "Command.h"
#include "IStoppable.h"
#include "ICommands.h"

class CommandLoop :
    public IStoppable,
    public ICommands
{
public:
    CommandLoop(std::istream& in, std::ostream& out);
    void Start();
    void Stop();
    const std::vector<Command*>& getCommands() const;
private:
    std::istream& in;
    std::ostream& out;
    bool running;
    std::vector<Command*> commands;
    void loop();
    std::vector<std::string> parseArgs(std::istringstream& linestream, unsigned int max);
};
