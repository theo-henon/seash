#include "print_visitor.hh"

namespace visitor
{
    PrintVisitor::PrintVisitor()
        : output_(std::cout)
    {}

    PrintVisitor::PrintVisitor(std::ostream& output)
        : output_(output)
    {}

    int PrintVisitor::visit_simple_cmd(ast::SimpleCmd* simple_cmd)
    {
        output_ << simple_cmd->concat_args();
        return 0;
    }

    int PrintVisitor::visit_pipeline(ast::Pipeline* pipeline)
    {
        if (pipeline->negate())
            output_ << "! ";
        size_t size = pipeline->size();
        size_t i = 0;
        for (; i < size - 1; i++)
        {
            visit_simple_cmd(pipeline->get_cmd(i));
            output_ << " | ";
        }
        visit_simple_cmd(pipeline->get_cmd(i));
        return 0;
    }
} // namespace visitor