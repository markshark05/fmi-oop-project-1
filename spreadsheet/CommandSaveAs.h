#pragma once
#include "Command.h"
#include "FileContext.h"
#include "Table.h"

class CommandSaveAs :
    public Command
{
private:
    FileContext* fileCtx;
    Table* table;
public:
    CommandSaveAs(FileContext& fileCtx, Table& table);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
