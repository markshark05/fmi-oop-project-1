#pragma once
#include "Command.h"
#include "FileContext.h"
#include "Table.h"

/**
 * @brief save - saves the currently open file
 * 
 */
class CommandSave :
    public Command
{
private:
    FileContext* fileCtx;
    Table* table;
public:
    CommandSave(FileContext& fileCtx, Table& table);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
