#pragma once
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief repsents a csv reader
 * splits lines by comma and parses escaped commas
 * 
 */
class CSVReader
{
public:
    std::vector<std::string> readCSVRow(std::istream& in) const;
};
