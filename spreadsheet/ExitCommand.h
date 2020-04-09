#pragma once
#include "Command.h"
#include "IStoppable.h"

class ExitCommand :
    public Command
{
public:
    ExitCommand(IStoppable* loop);
    const std::string execute() override;
private:
    IStoppable* _loop;
};
