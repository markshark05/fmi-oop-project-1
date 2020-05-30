#include "CSVWriter.h"

void CSVWriter::writeCSVRow(std::ostream& out, const std::vector<std::string>& csvRow)
{
    bool firstField = true;
    for (const std::string& field : csvRow)
    {
        if (!firstField)
        {
            out << ',';
        }
        firstField = false;
        
        bool quoted{ false };
        for (const char& c : field)
        {
            if (c == ',' || c == '"')
            {
                quoted = true;
                break;
            }
        }

        if (quoted) out << '"';
        for (const char& c : field)
        {
            if (c == '"') out << '"';
            out << c;
        }
        if (quoted) out << '"';
    }

    out << std::endl;
}
