#pragma once
#include "Command.h"
#include "ICommands.h"

class CommandHelp :
    public Command
{
public:
    CommandHelp(ICommands* commandLoop);
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
private:
    ICommands* _loop;
};
