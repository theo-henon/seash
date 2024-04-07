#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>

#include "lexer/lexer.hh"
#include "parser/parser.hh"
#include "visitor/execution_visitor.hh"
#include "visitor/print_visitor.hh"

int main(int argc, char* argv[])
{
    bool pretty_print = false;
    std::optional<std::string> filename;
    std::optional<std::string> script;

    // Parse options
    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]) == "-c")
        {
            if (++i < argc)
                script = argv[i];
            else
            {
                std::cerr << "Missing string argument for '-c' option"
                          << std::endl;
                return 1;
            }
        }
        else if (std::string(argv[i]) == "--pretty-print")
            pretty_print = true;
        else
            filename = argv[i];
    }

    if (script && filename)
    {
        std::cerr << "Unexpected argument: '" << *filename << '\''
                  << std::endl;
        return 1;
    }

    std::unique_ptr<ast::SimpleCmd> simple_cmd;
    if (script)
    {
        std::istringstream input(script.value());
        lexer::Lexer lexer(input);
        parser::Parser parser(lexer);
        simple_cmd = parser.parse_simple_cmd();
    }
    else if (filename)
    {
        std::ifstream input(*filename);
        if (!input.is_open())
            std::perror(filename->c_str());
        lexer::Lexer lexer(input);
        parser::Parser parser(lexer);
        simple_cmd = parser.parse_simple_cmd();
    }
    else
    {
        lexer::Lexer lexer(std::cin);
        parser::Parser parser(lexer);
        simple_cmd = parser.parse_simple_cmd();
    }

    if (simple_cmd == nullptr)
        return 1;

    if (pretty_print)
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
