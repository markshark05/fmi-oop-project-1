#include "Tokenizer.h"
#include <cctype>
#include <map>
#include <stdexcept>

std::vector<Token> Tokenizer::tokenize(const std::string& str)
{
    State s = State::Intial;
    std::vector<Token> tokens;
    std::string curr_str;

    for (size_t i = 0; i < str.length(); i++)
    {
        const char c = str[i];
        switch (s)
        {
        case State::Intial:
            if (isdigit(c))
            {
                s = State::Number_i;
                curr_str = c;
            }
            else
            {
                token_outside(s, tokens, curr_str, c);
            }
            break;
        case State::String:
            if (c == '\\')
            {
                s = State::String_e;
            }
            else if (c == '"')
            {
                tokens.push_back(Token(curr_str, Token::Type::String));
                s = State::Intial;
            }
            else
            {
                curr_str += c;
            }
            break;
        case State::String_e:
            if (c == '\\' || c == '"')
            {
                s = State::String;
                curr_str += c;
            }
            else
            {
                throw std::runtime_error(std::string("Error: Invalid escape character at ") + c);
            }
            break;
        case State::Number_i:
            if (isdigit(c))
            {
                curr_str += c;
            }
            else if (c == '.')
            {
                s = State::Number_f;
                curr_str += c;
            }
            else
            {
                tokens.push_back(Token(curr_str, Token::Type::Number_i));
                token_outside(s, tokens, curr_str, c);
            }
            break;
        case State::Number_f:
            if (isdigit(c))
            {
                curr_str += c;
            }
            else if (c == '.')
            {
                throw std::runtime_error(std::string("Error: Invalid number at ") + c);
            }
            else
            {
                tokens.push_back(Token(curr_str, Token::Type::Number_f));
                token_outside(s, tokens, curr_str, c);
            }
            break;
        }
    }

    // EOF
    switch (s)
    {
    case State::String:
    case State::String_e:
        throw std::runtime_error(std::string("Error: Unexpected end of file"));
    case State::Number_i:
        tokens.push_back(Token(curr_str, Token::Type::Number_i));
        break;
    case State::Number_f:
        tokens.push_back(Token(curr_str, Token::Type::Number_f));
        break;
    }

    return tokens;
}

void Tokenizer::token_outside(State& s, std::vector<Token>& tokens, std::string& curr_str, const char c)
{
    if (c == '"')
    {
        s = State::String;
        curr_str = "";
    }
    else
    {
        s = State::Intial;
        if (c == '+')
        {
            tokens.push_back(Token(std::to_string(c), Token::Type::Operator_Plus));
        }
        else if (c == '-')
        {
            tokens.push_back(Token(std::to_string(c), Token::Type::Operator_Minus));
        }
        else if (c == '*')
        {
            tokens.push_back(Token(std::to_string(c), Token::Type::Operator_Multiply));
        }
        else if (c == '/')
        {
            tokens.push_back(Token(std::to_string(c), Token::Type::Operator_Divide));
        }
        else if (c == '^')
        {
            tokens.push_back(Token(std::to_string(c), Token::Type::Operator_Pow));
        }
        else if (c == '=')
        {
            tokens.push_back(Token(std::to_string(c), Token::Type::Operator_Equals));
        }
        else if (c == 'R')
        {
            tokens.push_back(Token(std::to_string(c), Token::Type::Identifier_R));
        }
        else if (c == 'C')
        {
            tokens.push_back(Token(std::to_string(c), Token::Type::Identifier_C));
        }
        else if (!isblank(c))
        {
            throw std::runtime_error(std::string("Error: Invalid token at ") + c);
        }
    }
}