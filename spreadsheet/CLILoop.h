#pragma once
#include <vector>
#include "Command.h"
#include "IStoppableLoop.h"
#include "ICommandsLoop.h"

class CLILoop :
    public IStoppableLoop,
    public ICommandsLoop
{
private:
    std::istream* in;
    std::ostream* out;
    std::vector<Command*>* commands;
    bool running;
public:
    CLILoop(std::istream& in, std::ostream& out, std::vector<Command*>& commands);
    void start();
    void stop();
    const std::vector<Command*>& getCommands() const;
private:
    void loop();
    std::vector<std::string> parseArgs(std::istringstream& linestream);
};
