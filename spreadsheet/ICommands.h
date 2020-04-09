#pragma once
#include <vector>
#include "Command.h"

class ICommands
{
public:
    virtual const std::vector<Command*>& getCommands() const = 0;
};