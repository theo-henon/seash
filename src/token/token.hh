#pragma once

#include <cstdint>
#include <string>
#include <ostream>

namespace token
{
    class Token
    {
    public:
        Token(uint32_t row, uint32_t col);
        virtual ~Token() = default;

        [[nodiscard]] uint32_t get_row() const;
        [[nodiscard]] uint32_t get_col() const;
        [[nodiscard]] virtual const std::string& to_string() const = 0;

    private:
        const uint32_t row_;
        const uint32_t col_;
    };
} // namespace token