#pragma once
#include <ostream>
#include <string>
#include <vector>

class CSVWriter
{
public:
    void writeCSVRow(std::ostream& out, const std::vector<std::string>& csvRow);
};
