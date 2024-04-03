#pragma once

#include "visitor.hh"

namespace visitor
{
    class ExecutionVisitor : public Visitor
    {
    public:
        int visit_simple_cmd(ast::SimpleCmd* simple_cmd) const override;
    };
} // namespace visitor