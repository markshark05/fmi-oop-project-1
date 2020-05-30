#pragma once
#include <string>
#include <map>

#include "Cell.h"
#include "CSVReader.h"
#include "CSVWriter.h"
#include "Tokenizer.h"
#include "ExpressionParser.h"

class Table
{
private:
    const CSVReader* reader;
    const CSVWriter* writer;
    const Tokenizer* tokenizer;
    const ExpressionParser* parser;

    std::map<std::pair<unsigned, unsigned>, Cell> table;

    unsigned rows;
    unsigned cols;
public:
    Table(const CSVReader& reader, const CSVWriter& writer, const Tokenizer& tokenizer, const ExpressionParser& parser);
    unsigned getRows() const;
    unsigned getCols() const;

    std::string getCellValue(unsigned row, unsigned col) const;

    bool load(const std::string& fileName);
    bool save(const std::string& fileName);
};
