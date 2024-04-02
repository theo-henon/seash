#include <iostream>
#include <cstdlib>

#include "lexer/lexer.hh"

int main()
{
    lexer::Lexer lexer(std::cin);
    auto token = lexer.lex();
    std::string cmd;
    while (token != nullptr)
    {
        cmd += token->to_string() + " ";
        token = lexer.lex();
    }

    return std::system(cmd.c_str());
}