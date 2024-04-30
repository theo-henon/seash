#include "pipeline.hh"

#include "visitor/visitor.hh"

namespace ast
{
    bool Pipeline::negate() const
    {
        return negate_;
    }

    size_t Pipeline::size() const
    {
        return cmds_.size();
    }

    SimpleCmd* Pipeline::get_cmd(size_t index) const
    {
        return cmds_[index];
    }

    void Pipeline::add_cmd(SimpleCmd* cmd)
    {
        cmds_.push_back(cmd);
    }

    int Pipeline::accept(visitor::Visitor* visitor)
    {
        return visitor->visit_pipeline(this);
    }
} // namespace ast