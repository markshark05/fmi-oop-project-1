#pragma once
#include <vector>
#include "Token.h"

/**
 * @brief Represents a table cell as a collection of tokens
 * 
 */
class Cell
{
private:
    std::vector<Token> tokens;
public:
    /**
     * @brief Construct a new Cell object with emtpy token vector
     * 
     */
    Cell();
    /**
     * @brief Construct a new Cell object with given tokens
     * 
     * @param tokens 
     */
    Cell(const std::vector<Token>& tokens);
    /**
     * @brief Get the Tokens vector
     * 
     * @return const std::vector\<Token\>& 
     */
    const std::vector<Token>& getTokens() const;
};

