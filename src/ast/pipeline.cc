#include "pipeline.hh"

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

    const SimpleCmd* Pipeline::get_cmd(size_t index) const
    {
        return cmds_[index];
    }
} // namespace ast