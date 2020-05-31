#pragma once
#include "Command.h"
#include "Table.h"
#include "FileContext.h"

/**
 * @brief edit \<RnCn\> - prompts for the new value of the cell
 * 
 */
class CommandEdit :
    public Command
{
private:
    const FileContext* fileCtx;
    Table* table;
public:
    /**
     * @brief Construct a new CommandEdit
     * 
     * @param fileCtx the active file
     * @param table the table
     */
    CommandEdit(const FileContext& fileCtx, Table& table);
    bool fileRequirement();
    /**
     * fileCtx gets the active file\n 
     * delegates to table to save the cellStr
     */
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
