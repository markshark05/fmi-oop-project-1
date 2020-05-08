#pragma once
#include "Command.h"

class CommandSave :
    public Command
{
public:
    CommandSave();
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
};
