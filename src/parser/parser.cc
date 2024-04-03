#include "parser.hh"

namespace parser
{
    Parser::Parser(lexer::Lexer& lexer)
        : lexer_(lexer)
    {}

    std::unique_ptr<ast::SimpleCmd> Parser::parse_simple_cmd()
    {
        auto word = lexer_.lex();
        if (word == nullptr)
            return nullptr;

        auto simple_cmd = std::make_unique<ast::SimpleCmd>();
        do
        {
            simple_cmd->add_arg(word->to_string());
            word = lexer_.lex();
        } while (word != nullptr);

        return simple_cmd;
    }
} // namespace parser