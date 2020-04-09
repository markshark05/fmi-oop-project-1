#pragma once
#include "Command.h"

class SaveAsCommand :
    public Command
{
public:
    SaveAsCommand();
    const std::string execute() override;
};
