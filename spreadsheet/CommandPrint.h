#pragma once
#include "Command.h"
#include "FileContext.h"
#include "Table.h"

class CommandPrint :
    public Command
{
private:
    const FileContext* fileCtx;
    const Table* table;
public:
    CommandPrint(const FileContext& fileCtx, const Table& table);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
