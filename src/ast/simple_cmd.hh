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

        void add_arg(const std::string& arg);
        [[nodiscard]] char** c_args() const;
        [[nodiscard]] std::string concat_args() const;
        [[nodiscard]] size_t argc() const;
        [[nodiscard]] const std::string& get_arg(size_t index) const;
        int accept(visitor::Visitor* visitor) override;

    private:
        std::vector<std::string> argv_;
    };
} // namespace ast