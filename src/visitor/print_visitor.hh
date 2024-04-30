#pragma once

#include <iostream>

#include "visitor.hh"

namespace visitor
{
    class PrintVisitor : public Visitor
    {
    public:
        PrintVisitor();
        explicit PrintVisitor(std::ostream& output);

        int visit_simple_cmd(ast::SimpleCmd* simple_cmd) override;
        int visit_pipeline(ast::Pipeline* pipeline) override;

    private:
        std::ostream& output_;
    };
} // namespace visitor