#include <boost/program_options.hpp>
#include <iostream>
#include <sstream>

#include "lexer/lexer.hh"
#include "parser/parser.hh"
#include "visitor/execution_visitor.hh"
#include "visitor/print_visitor.hh"

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    po::options_description options_desc("Options");
    options_desc.add_options()("help", "Produce help message")(
        "c,c", po::value<std::string>(),
        "Execute script from string passed as argument")(
        "pretty-print", "Enable pretty pretting of the AST");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, options_desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        std::cout << options_desc << std::endl;
        return 0;
    }

    if (vm.count("c"))
    {
        std::istringstream input(vm["c"].as<std::string>());
        lexer::Lexer lexer(input);
        parser::Parser parser(lexer);
        auto simple_cmd = parser.parse_simple_cmd();

        if (vm.count("pretty-print"))
        {
            visitor::PrintVisitor print_visitor;
            return simple_cmd->accept(&print_visitor);
        }
        else
        {
            visitor::ExecutionVisitor execution_visitor;
            return simple_cmd->accept(&execution_visitor);
        }
    }
    else
    {
        lexer::Lexer lexer(std::cin);
        parser::Parser parser(lexer);
        auto simple_cmd = parser.parse_simple_cmd();

        if (vm.count("pretty-print"))
        {
            visitor::PrintVisitor print_visitor;
            return simple_cmd->accept(&print_visitor);
        }
        else
        {
            visitor::ExecutionVisitor execution_visitor;
            return simple_cmd->accept(&execution_visitor);
        }
    }
}