#pragma once

#include "echo.hh"

namespace builtins
{
    class Builtins
    {
    public:
        static bool is_builtin(const ast::SimpleCmd& simple_cmd) ;
        [[nodiscard]] int run_builtin(const ast::SimpleCmd& simple_cmd, const std::string& name) const;
    private:
        Echo echo_;
    };
} // namespace builtins