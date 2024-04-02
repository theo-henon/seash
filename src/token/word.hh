#pragma once

#include "token.hh"

namespace token
{
    class Word : public Token
    {
    public:
        Word(uint32_t row, uint32_t col, std::string value);
        virtual ~Word() = default;

        [[nodiscard]] const std::string& to_string() const override;

    private:
        std::string value_;
    };
} // namespace token