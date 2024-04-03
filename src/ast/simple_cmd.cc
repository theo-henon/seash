#include "simple_cmd.hh"

namespace ast
{
    size_t SimpleCmd::argc() const
    {
        return argv_.size();
    }

    std::ostream& operator<<(std::ostream& lhs, const SimpleCmd& simple_cmd)
    {
        for (size_t i = 0; i < simple_cmd.argv_.size() - 1 ; i++)
            lhs << simple_cmd.argv_[i] << " ";
        return lhs << *(simple_cmd.argv_.end() - 1);
    }

    void SimpleCmd::add_arg(const std::string& arg)
    {
        argv_.push_back(arg);
    }
} // namespace ast