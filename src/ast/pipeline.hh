#pragma once

#include <vector>

#include "ast.hh"
#include "simple_cmd.hh"

namespace ast
{

    class Pipeline : public Ast
    {
    public:
        ~Pipeline() override = default;

        [[nodiscard]] bool negate() const;
        [[nodiscard]] size_t size() const;
        [[nodiscard]] const SimpleCmd* get_cmd(size_t index) const;
        int accept(visitor::Visitor* visitor) override;
    private:
        std::vector<SimpleCmd*> cmds_;
        bool negate_;
    };

} // namespace ast