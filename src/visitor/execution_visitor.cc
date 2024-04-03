#include "execution_visitor.hh"

namespace visitor
{
    int ExecutionVisitor::visit_simple_cmd(ast::SimpleCmd* simple_cmd) const
    {
        return std::system(simple_cmd->concat_args().c_str());
    }
} // namespace visitor