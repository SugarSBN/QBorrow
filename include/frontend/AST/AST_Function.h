
#pragma once

#include "AST_Register.h"
#include "AST_Stmt.h"

struct Function {
    std :: string name_;
    std :: vector<std :: string> params_;
    std :: vector<std :: shared_ptr<Register> > registers_;
    std :: vector<std :: shared_ptr<Stmt> > body_;

    Function(const std :: string& name, 
             const std :: vector<std :: string>& params, 
             const std :: vector<std :: shared_ptr<Register> >& registers,
             const std :: vector<std :: shared_ptr<Stmt> >& body)
        : name_(name), params_(params), registers_(registers), body_(body) {}
    
    static std :: shared_ptr<Function> make_function(const std :: string& name, 
                                            const std :: vector<std :: string>& params, 
                                            const std :: vector<std :: shared_ptr<Register> >& registers,
                                            const std :: vector<std :: shared_ptr<Stmt> >& body);

    void print_function(std :: ostream& os = std :: cout) const;

};