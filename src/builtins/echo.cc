#include "echo.hh"

namespace builtins
{
    int Echo::operator()(const ast::SimpleCmd& simple_cmd) const
    {
        size_t argc = simple_cmd.argc();
        for (size_t i = 0; i < argc - 1; i++)
            std::cout << simple_cmd.get_arg(i) << ' ';
        std::cout << simple_cmd.get_arg(argc) << std::endl;
        return 0;
    }
} // namespace builtins