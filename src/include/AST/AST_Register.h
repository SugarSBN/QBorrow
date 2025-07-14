#pragma once

#include "AST_Expr.h"

struct Register {
    std :: string name_;
    std :: shared_ptr<Expr> size_;

    static std :: shared_ptr<Register> make_register(const std :: string& name, std :: shared_ptr<Expr> size);

    void print_register(std :: ostream& os = std :: cout) const;
};
