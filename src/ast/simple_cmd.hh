#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "ast.hh"

namespace ast
{
    class SimpleCmd : public Ast
    {
    public:
        ~SimpleCmd() override = default;

        [[nodiscard]] size_t argc() const;
        void add_arg(const std::string& arg);
        [[nodiscard]] std::string concat_args() const;
        int accept(visitor::Visitor* visitor) override;

    private:
        std::vector<std::string> argv_;
    };
} // namespace ast