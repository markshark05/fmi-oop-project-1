#pragma once
#include "Command.h"
#include "ICommands.h"

class HelpCommand :
    public Command
{
public:
    HelpCommand(ICommands* commandLoop);
    const std::string execute() override;
private:
    ICommands* _loop;
};

