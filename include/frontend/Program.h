
#pragma once

#include "AST_Expr.h"
#include "AST_Register.h"
#include "AST_Function.h"
#include "AST_Stmt.h"


class Program {

public:
    
    /*
        factory method to create a program
    */
    static std::shared_ptr<Program> make_program(const std::vector<std::shared_ptr<Function> >& functions,
                                                 const std::vector<std::shared_ptr<Stmt> >& statements);

    /*
        pretty print the program
    */
    void print_program(std::ostream& os = std::cout) const;

    std::vector<std::shared_ptr<Function> > get_functions() const;
    std::vector<std::shared_ptr<Stmt> > get_statements() const;


private:
    /*
        constructor
    */
    explicit Program(const std::vector<std::shared_ptr<Function> >& functions,
                     const std::vector<std::shared_ptr<Stmt> >& statements);


    std::vector<std::shared_ptr<Function> > functions_;
    std::vector<std::shared_ptr<Stmt> > statements_;
    
};