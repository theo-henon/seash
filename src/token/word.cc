#include "word.hh"

namespace token
{
    Word::Word(uint32_t row, uint32_t col, std::string value)
        : Token(row, col)
        , value_(std::move(value))
    {}

    const std::string& Word::to_string() const
    {
        return value_;
    }
} // namespace token