#include <iostream>
#include "ExpressionParser.h"
#include "Tokenizer.h"


int main(int argc, char* argv[]) {

    auto str = "123.344 + 456 / \"Haha xdd + R11C22 + \"The string is \\\"Hello, World\\\"\"5";
    std::cout << str << std::endl;
    auto t = Tokenizer();

    try {
        auto r = t.tokenize(str);
    }
    catch(std::exception e) {
        std::cout << e.what();
    }
}
