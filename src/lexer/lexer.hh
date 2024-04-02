#pragma once

#include <istream>
#include <memory>
#include <stack>

#include "token/token.hh"

namespace lexer
{
    using TokenPtr = std::shared_ptr<token::Token>;

    class Lexer
    {
    public:
        explicit Lexer(std::istream& input);

        [[nodiscard]] const TokenPtr& last() const;
        TokenPtr lex();

    private:
        std::istream& input_;
        std::stack<TokenPtr> tokens_stack_;
    };
} // namespace lexer