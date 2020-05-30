#include <iostream>
#include "Application.h"
#include "FileContext.h"
#include "CLILoop.h"
#include "CommandClose.h"
#include "CommandExit.h"
#include "CommandHelp.h"
#include "CommandOpen.h"
#include "CommandSave.h"
#include "CommandSaveAs.h"
#include "CommandEdit.h"
#include "CommandPrint.h"

void Application::run()
{
    FileContext fileCtx;
    
    std::vector<Command*> commands
    {
        new CommandOpen{ fileCtx },
        new CommandClose{ fileCtx },
        new CommandSave{ fileCtx },
        new CommandSaveAs{ fileCtx },

        new CommandEdit,
        new CommandPrint,
    };

    CLILoop cmdloop{ std::cin, std::cout, commands };

    commands.push_back(new CommandHelp{ cmdloop });
    commands.push_back(new CommandExit{ cmdloop });

    cmdloop.start();

    for (Command*& c : commands) delete c;
}
