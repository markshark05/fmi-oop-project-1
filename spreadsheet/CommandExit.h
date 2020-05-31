#pragma once
#include "Command.h"
#include "IStoppableLoop.h"

/**
 * @brief exit - exists the program
 * 
 */
class CommandExit :
    public Command
{
private:
    IStoppableLoop* _loop;
public:
    /**
     * @brief Construct a new CommandExit
     * 
     * @param loop reference to the command loop
     */
    CommandExit(IStoppableLoop& loop);
    /**
     * calls loop.stop()
    */
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
