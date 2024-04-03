#include "simple_cmd.hh"

#include <algorithm>

#include "visitor/visitor.hh"

namespace ast
{

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

    const char** SimpleCmd::c_args() const
    {
        const char **args = new const char*[argv_.size() + 1];
        std::transform(argv_.begin(), argv_.end(), args, [](const std::string& str){return str.c_str();});
        return args;
    }

} // namespace ast