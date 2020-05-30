#pragma once
#include <sstream>
#include <string>
#include <vector>

class CSVReader
{
public:
    std::vector<std::string> readCSVRow(std::istream& in);
};
