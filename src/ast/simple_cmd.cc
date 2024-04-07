#include "simple_cmd.hh"

#include <algorithm>

#include "visitor/visitor.hh"

namespace ast
{

    void SimpleCmd::add_arg(const std::string& arg)
    {
        argv_.push_back(arg);
    }

    std::string SimpleCmd::concat_args() const
    {
        std::string cmd;
        for (auto i = argv_.begin(); i < argv_.end() - 1; i++)
            cmd += *i + " ";
        cmd += *(argv_.end() - 1);
        return cmd;
    }

    char** SimpleCmd::c_args() const
    {
        char **args = new char*[argv_.size() + 1];
        for (size_t i = 0; i < argv_.size(); i++)
        {
            args[i] = new char[argv_[i].size() + 1];
            argv_[i].copy(args[i], argv_[i].size());
            args[i][argv_[i].size()] = '\0';
        }
        args[argv_.size()] = nullptr;
        return args;
    }

    size_t SimpleCmd::argc() const
    {
        return argv_.size();
    }

    const std::string& SimpleCmd::get_arg(size_t index) const
    {
        return argv_[index];
    }

    int SimpleCmd::accept(visitor::Visitor* visitor)
    {
        return visitor->visit_simple_cmd(this);
    }
} // namespace ast