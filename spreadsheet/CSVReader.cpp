#include "CSVReader.h"

std::vector<std::string> CSVReader::readCSVRow(std::istream& in)
{
    std::string row;
    std::getline(in, row);
    std::istringstream rowstream{ row };

    std::vector<std::string> fields{ "" };
    bool escaped = false;
    char c;
    while(rowstream.get(c))
    {
        if (!escaped)
        {
            switch (c)
            {
            case ',':
                fields.push_back("");
                break;
            case '\\': 
                escaped = true;
                break;
            default: 
                fields.back().push_back(c);
                break;
            }
        }
        else
        {
            switch (c)
            {
            case ',':
                fields.back().push_back(c);
                break;
            default:
                fields.back().push_back('\\');
                fields.back().push_back(c);
                break;
            }
            escaped = false;
        }
    }

    return fields;
}
