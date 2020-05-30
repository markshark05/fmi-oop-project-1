#include <fstream>
#include "Table.h"
#include "ExpressionParser.h"

Table::Table(const CSVReader& reader, const CSVWriter& writer, const Tokenizer& tokenizer, const ExpressionParser& parser) :
    rows(0),
    cols(0),
    reader(&reader),
    writer(&writer),
    tokenizer(&tokenizer),
    parser(&parser)
{
}

unsigned Table::getRows() const
{
    return rows;
}

unsigned Table::getCols() const
{
    return cols;
}

std::string Table::getCellValue(unsigned row, unsigned col) const
{
    std::pair<unsigned, unsigned> key{ row, col };

    if (table.count(key))
    {
        const Cell& cell{ table.at(key) };
        std::vector<Token> tokens{ cell.getTokens() };

        switch (tokens.size())
        {
        case 0:
            return "";
        case 1:
        {
            Token t = tokens[0];
            return t.getValue();
        }
        default:
        {
            Token t = tokens[0];
            switch (t.getType())
            {
            case Token::Type::Operator_Equals:
            {
                double value = parser->evaluate(cell.getTokens());
                if (trunc(value) == value)
                {
                    return std::to_string(static_cast<int>(value));
                }
                return std::to_string(value);
            }
            default:
                return "ERROR";
            }
        }
        }
    }

    return "";
}

bool Table::load(const std::string& fileName)
{
    std::fstream file{ fileName, std::ios::in | std::ios::out | std::fstream::app };
    if (!file)
    {
        return false;
    }

    table.clear();
    rows = 0;
    cols = 0;

    unsigned row_i = 0;
    while (file)
    {
        unsigned col_i = 0;
        std::vector<std::string> row = reader->readCSVRow(file);
        for (const std::string& cellStr : row)
        {
            std::vector<Token> tokens = tokenizer->tokenize(cellStr);
            Cell cell{ tokens };
            table[{ row_i, col_i  }] = cell;
            col_i++;
        }
        row_i++;
        cols = std::max(cols, col_i);
    }
    rows = row_i;

    return true;
}

bool Table::save(const std::string& fileName)
{
    return 0;
}
