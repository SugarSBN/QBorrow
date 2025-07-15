#pragma once

#include "AST_Expr.h"

class Register {

public:


    /*
        factory method to create a register
    */
    static std::shared_ptr<Register> make_register(const std::string& name, const std::shared_ptr<Expr>& size);

    /*
        pretty print registers
    */
    void print_register(std::ostream& os = std::cout) const;

    /*
        substitute the register with a new expression
    */
    std::shared_ptr<Register> substitute(const std::string& name, const std::shared_ptr<Expr>& value) const;

    std::string get_name() const;
    std::shared_ptr<Expr> get_size() const;

private:
    /*
        Constructors
    */
    explicit Register(const std::string& name, const std::shared_ptr<Expr>& size);
    

    std::string name_;
    std::shared_ptr<Expr> size_;

};
