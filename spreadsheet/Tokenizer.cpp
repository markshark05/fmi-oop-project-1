#include "Tokenizer.h"
#include <cctype>
#include <map>
#include <stdexcept>

Tokenizer::Tokenizer(const std::string& str) :
    str(str),
    s(State::Intial)
{
}

std::vector<Token> Tokenizer::getTokens() const
{
    return tokens;
}

bool Tokenizer::tokenize()
{
    std::string curr_str;
    for (unsigned i = 0; i < str.length(); i++)
    {
        const char c{ str[i] };
        switch (s)
        {
        case State::Intial:
            if (isdigit(c))
            {
                s = State::Number_i;
                curr_str = c;
            }
            else if (c == '"')
            {
                s = State::String;
                curr_str = "";
            }
            else if (c == 'R')
            {
                s = State::Identifier_r;
                curr_str = c;
            }
            else if (c == '+')
            {
                tokens.push_back(Token(c, Token::Type::Operator_Plus));
            }
            else if (c == '-')
            {
                tokens.push_back(Token(c, Token::Type::Operator_Minus));
            }
            else if (c == '*')
            {
                tokens.push_back(Token(c, Token::Type::Operator_Multiply));
            }
            else if (c == '/')
            {
                tokens.push_back(Token(c, Token::Type::Operator_Divide));
            }
            else if (c == '^')
            {
                tokens.push_back(Token(c, Token::Type::Operator_Pow));
            }
            else if (c == '=')
            {
                tokens.push_back(Token(c, Token::Type::Operator_Equals));
            }
            else if (!isblank(c))
            {
                return false;
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
            s = State::String;
            curr_str += c;
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
            else if (c == '"')
            {
                s = State::String;
                curr_str = "";
            }
            else
            {
                tokens.push_back(Token(curr_str, Token::Type::Number_i));
                s = State::Intial;
                i--; // process the char in initial state
            }
            break;
        case State::Number_f:
            if (isdigit(c))
            {
                curr_str += c;
            }
            else if (c == '"')
            {
                s = State::String;
                curr_str = "";
            }
            else
            {
                tokens.push_back(Token(curr_str, Token::Type::Number_f));
                s = State::Intial;
                i--; // process the char in initial state
            }
            break;
        case State::Identifier_r:
            if (isdigit(c))
            {
                s = State::Identifier_r_n;
                curr_str += c;
            }
            else
            {
                return false;
            }
            break;
        case State::Identifier_r_n:
            if (isdigit(c))
            {
                curr_str += c;
            }
            else if (c == 'C')
            {
                s = State::Identifier_c;
                curr_str += c;
            }
            else
            {
                return false;
            }
            break;
        case State::Identifier_c:
            if (isdigit(c))
            {
                s = State::Identifier_c_n;
                curr_str += c;
            }
            else
            {
                return false;
            }
            break;
        case State::Identifier_c_n:
            if (isdigit(c))
            {
                curr_str += c;
            }
            else
            {
                tokens.push_back(Token(curr_str, Token::Type::Identifier));
                s = State::Intial;
                i--; // process the char in initial state
            }
            break;
        }
    }

    // EOF
    switch (s)
    {
    case State::String:
    case State::String_e:
        tokens.push_back(Token(curr_str, Token::Type::String));
        break;
    case State::Number_i:
        tokens.push_back(Token(curr_str, Token::Type::Number_i));
        break;
    case State::Number_f:
        tokens.push_back(Token(curr_str, Token::Type::Number_f));
        break;
    case State::Identifier_c_n:
        tokens.push_back(Token(curr_str, Token::Type::Identifier));
        break;
    }

    return true;
}
