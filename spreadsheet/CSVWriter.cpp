#include "CSVWriter.h"

void CSVWriter::writeCSVRow(std::ostream& out, const std::vector<std::string>& csvRow) const
{
    bool firstField = true;
    for (const std::string& field : csvRow)
    {
        if (!firstField)
        {
            out << ',';
        }
        firstField = false;
        
        for (const char& c : field)
        {
            if (c == ',') out << '\\';
            out << c;
        }
    }

    out << std::endl;
}
