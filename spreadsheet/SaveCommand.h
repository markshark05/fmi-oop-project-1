#pragma once
#include "Command.h"

class SaveCommand :
    public Command
{
public:
    SaveCommand();
    const std::string execute() override;
};
