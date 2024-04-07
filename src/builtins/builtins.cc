#include "builtins.hh"

namespace builtins
{
    bool Builtins::is_builtin(const ast::SimpleCmd& simple_cmd)
    {
        return simple_cmd.get_arg(0) == "echo";
    }

    int Builtins::run_builtin(const ast::SimpleCmd& simple_cmd,
                              const std::string& name) const
    {
        if (name == "echo")
            return echo_(simple_cmd);
        return 0;
    }
} // namespace builtins