#pragma once

namespace visitor
{
    class Visitor;
}

namespace ast
{
    class Ast
    {
    public:
        virtual ~Ast() = default;

        virtual int accept(visitor::Visitor* visitor) = 0;
    };
} // namespace ast