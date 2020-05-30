#include "CSVReader.h"

std::vector<std::string> CSVReader::readCSVRow(std::istream& in)
{
    std::string row;
    std::getline(in, row);
    std::istringstream rowstream{ row };

    CSVState state = CSVState::Initial;
    std::vector<std::string> fields{ "" };
    int field_i = 0;
    char c;
    while(rowstream.get(c))
    {
        switch (state)
        {
        case CSVState::Initial:
            switch (c)
            {
            case ',':
                fields.push_back(""); field_i++;
                break;
            case '"': state = CSVState::Quoted;
                break;
            default: fields[field_i].push_back(c);
                break;
            }
            break;
        case CSVState::Quoted:
            switch (c)
            {
            case '"': state = CSVState::QuotedQuote;
                break;
            default: fields[field_i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedQuote:
            switch (c)
            {
            case ',':
                fields.push_back(""); field_i++;
                state = CSVState::Initial;
                break;
            case '"':
                fields[field_i].push_back('"');
                state = CSVState::Quoted;
                break;
            default:
                state = CSVState::Initial;
                break;
            }
            break;
        }
    }

    return fields;
}
