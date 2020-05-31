#pragma once
#include <ostream>
#include <string>
#include <vector>

/**
 * @brief repsents a csv writer
 * joins strings with comma and escapes commas in them
 * 
 */
class CSVWriter
{
public:
    /**
     * @brief performs the csv write
     * 
     * @param out the stream to write to
     * @param csvRow the data
     */
    void writeCSVRow(std::ostream& out, const std::vector<std::string>& csvRow) const;
};
