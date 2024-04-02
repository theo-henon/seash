#include <cstdlib>
#include <iostream>

#include "token/word.hh"

int main()
{
    token::Word echo(0, 0, "echo");
    std::cout << echo.to_string() << std::endl;
    return 0;
}