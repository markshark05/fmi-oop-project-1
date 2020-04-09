#pragma once
#include "Command.h"

class OpenCommand :
    public Command
{
public:
    OpenCommand();
    const std::string execute() override;
};
