#pragma once
#include "Command.h"
#include "IStoppable.h"

class CommandExit :
    public Command
{
public:
    CommandExit(IStoppable* loop);
    void execute(std::ostream& out, const std::vector<std::string>& args) override;
private:
    IStoppable* _loop;
};
