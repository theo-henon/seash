#pragma once

#include "ast/simple_cmd.hh"
namespace builtins
{
    class Echo
    {
    public:
        int operator()(const ast::SimpleCmd& simple_cmd);
    };
} // namespace builtins