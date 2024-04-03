#include <iostream>

#include "lexer/lexer.hh"
#include "parser/parser.hh"
#include "visitor/execution_visitor.hh"
#include "visitor/print_visitor.hh"

int main()
{
    lexer::Lexer lexer(std::cin);
    parser::Parser parser(lexer);
    auto simple_cmd = parser.parse_simple_cmd();
    visitor::PrintVisitor print_visitor;
    visitor::ExecutionVisitor execution_visitor;
    simple_cmd->accept(&print_visitor);
    std::cout << std::endl;
    simple_cmd->accept(&execution_visitor);
}