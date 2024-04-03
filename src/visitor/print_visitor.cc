#include "print_visitor.hh"

namespace visitor
{
    PrintVisitor::PrintVisitor()
        : output_(std::cout)
    {}

    PrintVisitor::PrintVisitor(std::ostream& output)
        : output_(output)
    {}

    int PrintVisitor::visit_simple_cmd(ast::SimpleCmd* simple_cmd) const
    {
        output_ << simple_cmd->concat_args();
        output_.flush();
        return 0;
    }
} // namespace visitor