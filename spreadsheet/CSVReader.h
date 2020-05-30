#pragma once
#include <sstream>
#include <string>
#include <vector>

class CSVReader
{
private:
    enum class CSVState
    {
        Initial,
        Quoted,
        QuotedQuote
    };
public:
    std::vector<std::string> readCSVRow(std::istream& in);
};
