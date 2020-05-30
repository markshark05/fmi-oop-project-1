#pragma once
#include "Command.h"
#include "FileContext.h"

class CommandSaveAs :
    public Command
{
private:
    FileContext* fileCtx;
public:
    CommandSaveAs(FileContext& fileCtx);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
