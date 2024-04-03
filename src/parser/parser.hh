#pragma once

#include "ast/simple_cmd.hh"
#include "lexer/lexer.hh"
namespace parser
{
    class Parser
    {
    public:
        explicit Parser(lexer::Lexer& lexer);

        std::unique_ptr<ast::SimpleCmd> parse_simple_cmd();

    private:
        lexer::Lexer& lexer_;
    };
} // namespace parser