#pragma once
#include "Command.h"
#include "ICommandsLoop.h"

/**
 * @brief help - prints the help message of all commands
 * 
 */
class CommandHelp :
    public Command
{
private:
    const ICommandsLoop* _loop;
public:
    /**
     * @brief Construct a new CommandHelp
     * 
     * @param commandLoop reference to loop
     */
    CommandHelp(const ICommandsLoop& commandLoop);
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
