#pragma once
#include "Command.h"
#include "FileContext.h"

class CommandSave :
    public Command
{
private:
    FileContext* fileCtx;
public:
    CommandSave(FileContext& fileCtx);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
