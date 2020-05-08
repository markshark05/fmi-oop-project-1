#pragma once
#include "Command.h"

class CommandClose :
    public Command
{
public:
    CommandClose();
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
};
