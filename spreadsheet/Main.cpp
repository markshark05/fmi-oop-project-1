#include <iostream>

#include "CommandLoop.h"
#include "Command.h"


int main(int argc, char* argv[])
{
    CommandLoop loop{ std::cin, std::cout };

    loop.Start();
}
