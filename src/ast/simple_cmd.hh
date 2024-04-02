#pragma once

#include <ostream>
#include <string>
#include <vector>

namespace ast
{
    class SimpleCmd
    {
    public:
        [[nodiscard]] size_t argc() const;

        friend std::ostream& operator<<(std::ostream& lhs,
                                        const SimpleCmd& simple_cmd);

    private:
        std::vector<std::string> argv_;
    };
} // namespace ast