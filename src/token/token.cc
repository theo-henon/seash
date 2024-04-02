#include "token.hh"

namespace token
{
    Token::Token(uint32_t row, uint32_t col)
        : row_(row)
        , col_(col)
    {}

    uint32_t Token::get_row() const
    {
        return row_;
    }

    uint32_t Token::get_col() const
    {
        return col_;
    }
} // namespace token