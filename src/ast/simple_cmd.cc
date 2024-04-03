#include "simple_cmd.hh"

#include "visitor/visitor.hh"

namespace ast
{
    size_t SimpleCmd::argc() const
    {
        return argv_.size();
    }

    void SimpleCmd::add_arg(const std::string& arg)
    {
        argv_.push_back(arg);
    }

    int SimpleCmd::accept(visitor::Visitor* visitor)
    {
        return visitor->visit_simple_cmd(this);
    }
    std::string SimpleCmd::concat_args() const
    {
        std::string cmd;
        for (auto i = argv_.begin(); i < argv_.end() - 1; i++)
            cmd += *i + " ";
        cmd += *(argv_.end() - 1);
        return cmd;
    }

} // namespace ast