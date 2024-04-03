#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace visitor
{
    class Visitor;
}

namespace ast
{
    class SimpleCmd
    {
    public:
        [[nodiscard]] size_t argc() const;

        void add_arg(const std::string& arg);
        [[nodiscard]] std::string concat_args() const;
        int accept(visitor::Visitor* visitor);

    private:
        std::vector<std::string> argv_;
    };
} // namespace ast