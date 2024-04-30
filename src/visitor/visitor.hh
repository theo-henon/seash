#pragma once

#include "ast/pipeline.hh"
#include "ast/simple_cmd.hh"

namespace visitor
{
    class Visitor
    {
    public:
        virtual int visit_simple_cmd(ast::SimpleCmd* simple_cmd) = 0;
        virtual int visit_pipeline(ast::Pipeline* pipeline) = 0;
    };
} // namespace visitor