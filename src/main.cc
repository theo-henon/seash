#include <iostream>

#include "lexer/lexer.hh"
#include "parser/parser.hh"
#include "visitor/execution_visitor.hh"

int main()
{
    lexer::Lexer lexer(std::cin);
    parser::Parser parser(lexer);
    auto simple_cmd = parser.parse_simple_cmd();
    visitor::ExecutionVisitor execution_visitor;
    simple_cmd->accept(&execution_visitor);
}