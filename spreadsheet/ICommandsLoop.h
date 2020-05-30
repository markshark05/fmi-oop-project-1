#pragma once
#include <vector>
#include "Command.h"

class ICommandsLoop
{
public:
    virtual const std::vector<Command*>& getCommands() const = 0;
};