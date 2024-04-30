#include "echo.hh"

namespace builtins
{
    int Echo::operator()(const ast::SimpleCmd& simple_cmd) const
    {
        size_t argc = simple_cmd.argc();
        if (argc <= 1)
        {
            std::cout << '\n';
            return 0;
        }

        for (size_t i = 1; i < argc - 1; i++)
            std::cout << simple_cmd.get_arg(i) << ' ';
        std::cout << simple_cmd.get_arg(argc - 1);
        std::cout << '\n';
        std::cout.flush();
        return 0;
    }
} // namespace builtins