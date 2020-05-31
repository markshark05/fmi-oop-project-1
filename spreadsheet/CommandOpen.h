#pragma once
#include "Command.h"
#include "FileContext.h"
#include "Table.h"

/**
 * @brief open <file> - loads <file> creating new one if does not exist
 * 
 */
class CommandOpen :
    public Command
{
private:
    FileContext* fileCtx;
    Table* table;
public:
    CommandOpen(FileContext& fileCtx, Table& table);
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
