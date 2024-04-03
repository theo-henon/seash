#include <cstdlib>
#include <iostream>

#include "lexer/lexer.hh"
#include "parser/parser.hh"

int main()
{
    lexer::Lexer lexer(std::cin);
    parser::Parser parser(lexer);
    auto simple_cmd = parser.parse_simple_cmd();
    if (simple_cmd != nullptr)
        std::cout << *simple_cmd << std::endl;
}