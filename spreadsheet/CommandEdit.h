#pragma once
#include "Command.h"
#include "Table.h"
#include "FileContext.h"

class CommandEdit :
    public Command
{
private:
    const FileContext* fileCtx;
    Table* table;
public:
    CommandEdit(const FileContext& fileCtx, Table& table);
    bool fileRequirement();
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
