#include <iostream>
#include "ExpressionParser.h"
#include "Tokenizer.h"


int main(int argc, char* argv[]) {

    //while (1) {
    //    std::string str;
    //    std::cin >> str;
    //    std::cout << ExpressionParser::evaluate(str) << std::endl;
    //}

    auto str = "123.344 + 456 / \"Haha xdd\" + R11C22 + \"The string is \\\"Hello, World\\\"\"5";
    std::cout << str;
    auto t = Tokenizer();
    auto r = t.tokenize(str);
}
