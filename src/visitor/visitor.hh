#pragma once

#include "ast/simple_cmd.hh"

namespace visitor
{
    class Visitor
    {
    public:
        virtual int visit_simple_cmd(ast::SimpleCmd* simple_cmd) const = 0;
    };
} // namespace visitor