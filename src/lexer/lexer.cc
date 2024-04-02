#include "lexer.hh"

#include "token/word.hh"

namespace lexer
{
    Lexer::Lexer(std::istream& input)
        : input_(input)
    {}

    const TokenPtr& Lexer::last() const
    {
        return tokens_stack_.top();
    }

    TokenPtr Lexer::lex()
    {
        std::string token;
        if (!(input_ >> token))
            return nullptr;
        tokens_stack_.emplace(std::make_shared<token::Word>(0, 0, token));
        return tokens_stack_.top();
    }
} // namespace lexer