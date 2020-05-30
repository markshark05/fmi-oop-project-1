#pragma once
#include "Command.h"

class CommandPrint :
    public Command
{
public:
    CommandPrint();
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
