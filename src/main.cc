#include <boost/program_options.hpp>
#include <iostream>
#include <sstream>

#include "lexer/lexer.hh"
#include "parser/parser.hh"
#include "visitor/execution_visitor.hh"

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    po::options_description desc("Options");
    desc.add_options()("help", "Produce help message")(
        "c", po::value<std::string>(), "Execute script from string passed as argument")
        ("pretty-print", "Enable pretty pretting of the AST");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }

    if (vm.count("c"))
        std::cout << vm["c"].as<std::string>() << std::endl;

    if (vm.count("pretty-print"))
        std::cout << "Pretty print the AST" << std::endl;

    lexer::Lexer lexer(std::cin);
    parser::Parser parser(lexer);
    auto simple_cmd = parser.parse_simple_cmd();
    visitor::ExecutionVisitor execution_visitor;
    simple_cmd->accept(&execution_visitor);
    return 0;
}