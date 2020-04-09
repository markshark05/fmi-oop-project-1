#pragma once
#include "Command.h"

class CloseCommand :
    public Command
{
public:
    CloseCommand();
    const std::string execute() override;
};
