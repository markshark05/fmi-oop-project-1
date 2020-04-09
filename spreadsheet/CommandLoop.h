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
    CommandLoop();
    CommandLoop(std::vector<Command*>& commands);
    void Start();
    void Stop();
    const std::vector<Command*>& getCommands() const;
    void addCommand(Command* command);
private:
    void _loop();
    bool _running;
    std::vector<Command*> _commands;
};
