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
#include "ExpressionParser.h"

void Application::run()
{
    CSVReader reader;
    CSVWriter writer;
    ExpressionParser parser;

    Table table{ reader, writer, parser };
    FileContext fileCtx;
    std::vector<Command*> commands
    {
        new CommandOpen{ fileCtx, table },
        new CommandClose{ fileCtx },
        new CommandSave{ fileCtx, table },
        new CommandSaveAs{ fileCtx, table },

        new CommandEdit{ fileCtx, table },
        new CommandPrint{ fileCtx, table },
    };

    CLILoop cmdloop{ std::cin, std::cout, commands };

    commands.push_back(new CommandHelp{ cmdloop });
    commands.push_back(new CommandExit{ cmdloop });

    cmdloop.start();

    for (Command*& c : commands) delete c;
}
