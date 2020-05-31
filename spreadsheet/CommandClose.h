#pragma once
#include "Command.h"
#include "FileContext.h"

/**
 * @brief close - closes currently opened file
 * 
 */
class CommandClose :
    public Command
{
private:
    FileContext* fileCtx;
public:
    /**
     * @brief Construct a new CommandClose
     * 
     * @param fileCtx the active file
     */
    CommandClose(FileContext& fileCtx);
    bool fileRequirement() override;
    /**
     * clears the active file of fileCtx
     */
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
