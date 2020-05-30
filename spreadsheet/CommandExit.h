#pragma once
#include "Command.h"
#include "IStoppableLoop.h"

class CommandExit :
    public Command
{
private:
    IStoppableLoop* _loop;
public:
    CommandExit(IStoppableLoop& loop);
    void execute(std::istream& in, std::ostream& out, const std::vector<std::string>& args) override;
};
