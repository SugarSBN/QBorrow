#pragma once

#include "AST_Expr.h"

class Register final : public Printable, public Substitutable, public Evaluatable {

public:


    /*
        factory method to create a register
    */
    static std::shared_ptr<Register> make_register(const std::string& name, const std::shared_ptr<Expr>& size);
    


    
    void print(std::ostream& os ) const override;
    void substitute(const std::string& name, const std::shared_ptr<Expr>& value) override;
    void evaluate() override;



    const std::string& get_name() const;
    const std::shared_ptr<Expr>& get_size() const;
    
    void set_name(const std::string& name);

    std::shared_ptr<Register> clone() const;

private:
    /*
        Constructors
    */
    explicit Register(const std::string& name, const std::shared_ptr<Expr>& size);
    

    std::string name_;
    std::shared_ptr<Expr> size_;

};
