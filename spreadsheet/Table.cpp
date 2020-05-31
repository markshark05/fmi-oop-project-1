#include <fstream>
#include "Table.h"
#include "ExpressionParser.h"
#include "CellIdentifier.h"

Table::Table(const CSVReader& reader, const CSVWriter& writer, const ExpressionParser& parser) :
    rows(0),
    cols(0),
    reader(&reader),
    writer(&writer),
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

std::string Table::getCellString(unsigned row, unsigned col) const
{
    Token token = getCellValue(row, col);
    return token.getValue();
}

Token Table::getCellValue(unsigned row, unsigned col) const
{
    std::pair<unsigned, unsigned> key{ row, col };

    if (table.count(key))
    {
        std::vector<Token> tokens{ table.at(key).getTokens() };

        switch (tokens.size())
        {
        case 0:
            return {};
        case 1:
        {
            Token t = tokens[0];
            return t;
        }
        default:
        {
            Token t = tokens[0];
            switch (t.getType())
            {
            case Token::Type::Operator_Equals:
            {
                for (size_t i = 1; i < tokens.size(); i++)
                {
                    if (tokens[i].getType() == Token::Type::Identifier)
                    {
                        CellIdentifier id;
                        CellIdentifier::tryParse(tokens[i].getValue(), id);
                        tokens[i] = getCellValue(id.getRow(), id.getCol());
                    }
                }

                return parser->evaluate(tokens);
            }
            case Token::Type::Operator_Minus:
            case Token::Type::Operator_Plus:
            {
                Token t1 = tokens[1];
                switch (t1.getType())
                {
                case Token::Type::Number_i:
                case Token::Type::Number_f:
                    return { (t.getValue() + t1.getValue()), t1.getType() };
                default: return {};
                }
            }
            default:
                return {};
            }
        }
        }
    }

    return {};
}

bool Table::setCellValue(unsigned row, unsigned col, const std::string& cellStr)
{
    Tokenizer tokenizer{ cellStr };
    if (!tokenizer.tokenize())
    {
        return false;
    }
    std::vector<Token> tokens = tokenizer.getTokens();
    Cell cell{ tokens };
    table[{ row, col  }] = cell;
    return true;
}

bool Table::load(const std::string& fileName, TableError& error)
{
    std::fstream file{ fileName, std::ios::in | std::ios::out | std::fstream::app };
    if (!file)
    {
        error = { true };
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
            if (!setCellValue(row_i, col_i, cellStr))
            {
                error = { row_i , col_i };
                return false;
            }
            col_i++;
        }
        row_i++;
        cols = std::max(cols, col_i);
    }
    rows = row_i;

    return true;
}

bool Table::save(const std::string& fileName) const
{
    std::ofstream file{ fileName, std::ios::trunc };
    if (!file)
    {
        return false;
    }

    for (unsigned i = 0; i < rows; i++)
    {
        std::vector<std::string> row;
        for (unsigned j = 0; j < cols; j++)
        {
            std::ostringstream cellStr;
            if (table.count({ i, j }))
            {
                std::vector<Token> tokens = table.at({i, j}).getTokens();
                for (auto& t : tokens)
                {
                    cellStr << Tokenizer::stringify(t);
                }
            }
            
            row.push_back(cellStr.str());
        }
        
        writer->writeCSVRow(file, row);
    }

    return true;
}
