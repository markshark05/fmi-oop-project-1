#pragma once
#include "Command.h"
#include "FileContext.h"

class CommandOpen :
    public Command
{
private:
    FileContext* fileCtx;
public:
    CommandOpen(FileContext& fileCtx);
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
