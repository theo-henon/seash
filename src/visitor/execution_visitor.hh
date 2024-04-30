#pragma once

#include "builtins/builtins.hh"
#include "visitor.hh"

namespace visitor
{
    class ExecutionVisitor : public Visitor
    {
    public:
        int visit_simple_cmd(ast::SimpleCmd* simple_cmd) override;
        int visit_pipeline(ast::Pipeline* pipeline) override;

    private:
        builtins::Builtins builtins_{};
    };
} // namespace visitor