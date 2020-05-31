#pragma once
#include "Command.h"
#include "FileContext.h"
#include "Table.h"

/**
 * @brief print - prints the current table
 * 
 */
class CommandPrint :
    public Command
{
private:
    const FileContext* fileCtx;
    const Table* table;
public:
    /**
     * @brief Construct a new CommandPrint
     * 
     * @param fileCtx active file
     * @param table reference to table
     */
    CommandPrint(const FileContext& fileCtx, const Table& table);
    bool fileRequirement() override;
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
