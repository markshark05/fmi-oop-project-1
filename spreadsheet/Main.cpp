#include <iostream>

#include "CommandLoop.h"
#include "Command.h"
#include "Tokenizer.h"
#include "ExpressionParser.h"


int main(int argc, char* argv[])
{
    Tokenizer tokenizer;
    auto tokens{ tokenizer.tokenize("3 + 4 * 2 / 4 ^ 2 ^ 3") };
    //auto tokens{ tokenizer.tokenize("3 + 4 * 2 * 2 - 9") };
    //auto tokens{ tokenizer.tokenize("2^3^2") };

    ExpressionParser parser;
    auto value{ parser.evaluate(tokens) };

    //CommandLoop loop{ std::cin, std::cout };
    //loop.Start();
}
