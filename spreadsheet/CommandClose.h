#pragma once
#include "Command.h"
#include "FileContext.h"

class CommandClose :
    public Command
{
private:
    FileContext* fileCtx;
public:
    CommandClose(FileContext& fileCtx);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
