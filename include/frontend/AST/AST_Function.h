
#pragma once

#include "AST_Register.h"
#include "AST_Stmt.h"

class Function {

public:

    static std::shared_ptr<Function> make_function(const std::string& name, 
                                                   const std::vector<std::string>& params, 
                                                   const std::vector<std::shared_ptr<Register> >& registers,
                                                   const std::vector<std::shared_ptr<Stmt> >& body);
    std::string get_name() const;
    std::vector<std::string> get_params() const;
    std::vector<std::shared_ptr<Register> > get_registers() const;
    std::vector<std::shared_ptr<Stmt> > get_body() const;
    
    void print_function(std::ostream& os = std::cout) const;

private:

    explicit Function(const std::string& name, 
                      const std::vector<std::string>& params, 
                      const std::vector<std::shared_ptr<Register> >& registers,
                      const std::vector<std::shared_ptr<Stmt> >& body);
            
    std::string name_;
    std::vector<std::string> params_;
    std::vector<std::shared_ptr<Register> > registers_;
    std::vector<std::shared_ptr<Stmt> > body_;

};