#include "execution_visitor.hh"

#include <sys/wait.h>
#include <unistd.h>

namespace visitor
{
    int ExecutionVisitor::visit_simple_cmd(ast::SimpleCmd* simple_cmd)
    {
        if (builtins::Builtins::is_builtin(*simple_cmd))
            return builtins_.run_builtin(*simple_cmd, simple_cmd->get_arg(0));

        char** args = simple_cmd->c_args();
        pid_t pid = fork();
        if (pid == -1)
        {
            std::perror("Failed to fork");
            return 1;
        }

        if (pid == 0)
        {
            // Child
            if (execvp(args[0], args) == -1)
            {
                std::perror(args[0]);
                return 1;
            }
            return 0;
        }
        else
        {
            // Parent
            delete[] args;
            int status;
            waitpid(pid, &status, 0);
            return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
        }
    }
    int ExecutionVisitor::visit_pipeline(__attribute_maybe_unused__ ast::Pipeline* pipeline)
    {
        // TODO
        throw std::logic_error("Not yet implemented");
    }
} // namespace visitor